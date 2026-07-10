#include "stringset.hpp"

#include <algorithm>
#include <string>

namespace containers {
bool StringSet::contains(const std::string& data) const noexcept {
    auto it = std::lower_bound(this->set.begin(), this->set.end(), data);
    return it != this->set.end() && *it == data;
}

bool StringSet::add(const std::string& data) {
    auto it = std::lower_bound(this->set.begin(), this->set.end(), data);
    if (it != this->set.end() && *it == data) {
        return false;
    }
    set.insert(it, data);
    return true;
}

bool StringSet::remove(const std::string& data) {
    auto it = std::lower_bound(this->set.begin(), this->set.end(), data);
    if (it == this->set.end() || *it != data) {
        return false;
    }
    set.erase(it);
    return true;
}
} // namespace containers
