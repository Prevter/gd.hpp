// utils/versions.hpp
// ~~~~~~~~~~~~~~~~
// Contains methods for comparing versions.
// ~~~~~~~~~~~~~~~~

#pragma once

#include <string>
#include <vector>

namespace gd::utils
{
    class Version
    {
    public:
        Version(std::string const &version);

        // compare with other version
        bool operator==(Version const &other) const;
        bool operator!=(Version const &other) const;
        bool operator<(Version const &other) const;
        bool operator>(Version const &other) const;
        bool operator<=(Version const &other) const;
        bool operator>=(Version const &other) const;

        // compare with string
        bool operator==(std::string const &other) const;
        bool operator!=(std::string const &other) const;
        bool operator<(std::string const &other) const;
        bool operator>(std::string const &other) const;
        bool operator<=(std::string const &other) const;
        bool operator>=(std::string const &other) const;

        std::string const &getVersion() const;

    private:
        std::vector<int> m_version;
        std::string m_str;
    };
}