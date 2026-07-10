#pragma once

#include <string>
#include <vector>

namespace containers {
class StringSet {
public:
    StringSet() = default;
    StringSet(const StringSet&) = default;
    StringSet(StringSet&&) = default;
    StringSet& operator=(const StringSet&) = default;
    StringSet& operator=(StringSet&&) = default;
    ~StringSet() = default;

    bool add(const std::string& data);
    bool remove(const std::string& data);
    bool contains(const std::string& data) const noexcept;

private:
    std::vector<std::string> set;

};
} // namespace containers
