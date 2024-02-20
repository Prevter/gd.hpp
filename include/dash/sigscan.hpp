#pragma once

#include <cstdint>
#include <string>
#include <vector>

/// @brief Contains tools for signature scanning.
namespace gd::sigscan {
    /*
     * Pattern syntax:
     * ?  - any byte
     * ^  - set address cursor
     * *  - multi pattern (finds all matches)
     * 1F - byte value (any hex value)
     *
     * Example:
     * "*6A106A0CE8????84C0^750B8BCE"
     * 1. '*' tells to find all occurrences of the pattern
     * 2. Then match this pattern:
     * 6A 10 6A 0C E8 XX XX XX XX 84 C0 75 0B 8B CE
     *                                 ^
     * 3. Store address of the byte marked with '^' in the result
     *
     * This will return two addresses which we can use to patch the game.
     *
    */

    /*
     * Mask syntax:
     * ?                 - any byte
     * %([+/-]XX)        - add or subtract XX from original byte value
     * $([+/-]XX)        - get byte value from original_address + XX as offset
     * &([+/-]XX[+/-]YY) - combines % and $ (XX is offset, YY is value to add/subtract)
     * *XX               - repeat next mask token XX times
     * @N(PATTERN)       - look for a pattern and store a relative offset in N bytes (used for relative jumps)
     * 1F                - byte value (any hex value)
     *
     * Example 1:
     * "909090909090C6?%(-3A)2D??01E9"
     * 1. First 7 bytes ("909090909090C6") are simply replaced
     * 2. Next byte ("?") is left as is
     * 3. "%(-3A)" tells to subtract 0x3A from original byte value
     * 4. "2D ? ? 01 E9" does the same as step 1-2
     *
     * Example 2:
     * "E9&(01+01)*03$0190"
     * 1. "E9" is replaced
     * 2. "&(01+01)" takes the value of the byte with offset 0x01 (next byte),
     * adds 0x01 to it and stores it here
     * 3. "*03" tells to repeat the next mask token 3 times:
     *     - "$01" gets the value of the next byte
     * 4. "90" is replaced
     *
     * Example 3:
     * "E9@4(8BCBFF15????^8B4C24?64890D00000000595F5E)"
     * 1. "E9" is replaced (jmp)
     * 2. "@4" tells to look for a pattern and store a relative offset in 4 bytes
     * 3. "(8BCBFF15????^8B4C24?64890D00000000595F5E)" is the pattern to look for (see pattern syntax)
     * If the offset for this pattern is 0x746, the final mask would be:
     * "E942070000" (jmp 0x747)
     * The changes from 0x746 to 0x742 and to 0x747 are explained by how relative jumps work in x86:
     * - 0x746 to 0x742 is calculated by subtracting 4 bytes because the jump address is 4 bytes long
     * - "E9 42070000" is actually "jmp 0x747" because the jump takes 5 bytes and jumps from it's end (0x742 + 5 = 0x747)
     *
    */

    /// @brief A pattern token
    struct PatternToken {
        bool any_byte;           // true if the byte is a wildcard
        uint8_t byte;            // value of the byte
        bool set_address_cursor; // true if the address cursor should be set to this byte
        bool multi_pattern;      // true if the pattern should be matched multiple times
        int8_t jump_if_fail;     // valid inside [] brackets, tells how many tokens to skip in the pattern if the match fails

        PatternToken() : any_byte(false), byte(0), set_address_cursor(false), multi_pattern(false), jump_if_fail(0) {}
    };

    /// @brief A mask token
    struct MaskToken {
        bool any_byte; // true if the byte is a wildcard

        bool is_pattern;  // true if the value should be an address to the pattern
        bool is_relative; // true if the byte value should be changed by a relative offset
        bool is_address;  // true if the value of the byte should be taken from original_address + offset

        // NOTE: if is_relative and is_address are both true,
        // the value of the byte will be taken from original_address + offset + value

        uint8_t value; // value to change the byte to
        int8_t offset; // offset to add to the value

        std::string pattern; // pattern to calculate the offset from

        MaskToken() : any_byte(false), is_pattern(false), is_relative(false), is_address(false), value(0), offset(0) {}
    };

    /// @brief Result of a pattern match
    struct Opcode {
        uintptr_t address;
        std::string library;
        std::vector<uint8_t> original;
        std::vector<uint8_t> patched;

        Opcode(uintptr_t address, std::string library, std::vector<uint8_t> original,
               std::vector<uint8_t> patched)
                : address(address),
                  library(std::move(library)),
                  original(std::move(original)),
                  patched(std::move(patched)) {}
    };

    /// @brief Parses a pattern string to get a list of tokens
    /// @param pattern Pattern string
    /// @return List of pattern tokens
    std::vector<PatternToken> parsePattern(const std::string &pattern);

    /// @brief Parses a mask string to get a list of tokens
    /// @param mask Mask string
    /// @return List of mask tokens
    std::vector<MaskToken> parseMask(const std::string &mask);

    /// @brief Finds a pattern in a library
    /// @param pattern A list of pattern tokens
    /// @param library Library name
    /// @return All found addresses
    std::vector<uintptr_t> findPattern(std::vector<PatternToken> pattern, const std::string &library = "");

    /// @brief Finds a pattern in a library
    /// @param pattern Pattern string
    /// @param library Library name
    /// @return All found addresses
    std::vector<uintptr_t> findPatterns(const std::string &pattern, const std::string &library = "");

    /// @brief Finds a pattern in a library
    /// @param pattern Pattern string
    /// @param library Library name
    /// @return The first found address
    uintptr_t findPattern(const std::string &pattern, const std::string &library = "");

    /// @brief Finds a pattern in a library
    /// @param pattern Pattern string
    /// @param mask Mask string
    /// @param library Library name
    /// @return All opcodes found
    std::vector<Opcode> match(const std::string &pattern, const std::string &mask = "", const std::string &library = "");
}