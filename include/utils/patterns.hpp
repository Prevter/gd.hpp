#pragma once

#include <utility>
#include <vector>
#include <string>
#include <cstdint>

namespace gd::patterns {

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
    std::vector<Opcode>
    match(const std::string &pattern, const std::string &mask = "", const std::string &library = "");

}