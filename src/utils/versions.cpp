#include <utils/versions.hpp>

namespace gd::utils
{
    Version::Version(std::string const &version)
    {
        m_str = version;

        std::string::size_type pos = 0;
        std::string::size_type prev = 0;
        std::string::size_type len = version.length();

        while ((pos = version.find('.', prev)) != std::string::npos)
        {
            m_version.push_back(std::stoi(version.substr(prev, pos - prev)));
            prev = pos + 1;
        }

        if (prev < len)
            m_version.push_back(std::stoi(version.substr(prev, std::string::npos)));
    }

    bool Version::operator==(Version const &other) const
    {
        return m_version == other.m_version;
    }

    bool Version::operator!=(Version const &other) const
    {
        return m_version != other.m_version;
    }

    bool Version::operator<(Version const &other) const
    {
        return m_version < other.m_version;
    }

    bool Version::operator>(Version const &other) const
    {
        return m_version > other.m_version;
    }

    bool Version::operator<=(Version const &other) const
    {
        return m_version <= other.m_version;
    }

    bool Version::operator>=(Version const &other) const
    {
        return m_version >= other.m_version;
    }

    bool Version::operator==(std::string const &other) const
    {
        return m_str == other;
    }

    bool Version::operator!=(std::string const &other) const
    {
        return m_str != other;
    }

    bool Version::operator<(std::string const &other) const
    {
        auto otherVersion = Version(other);
        return m_version < otherVersion.m_version;
    }

    bool Version::operator>(std::string const &other) const
    {
        auto otherVersion = Version(other);
        return m_version > otherVersion.m_version;
    }

    bool Version::operator<=(std::string const &other) const
    {
        auto otherVersion = Version(other);
        return m_version <= otherVersion.m_version;
    }

    bool Version::operator>=(std::string const &other) const
    {
        auto otherVersion = Version(other);
        return m_version >= otherVersion.m_version;
    }

    std::string const &Version::getVersion() const
    {
        return m_str;
    }
}