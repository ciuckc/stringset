#include "stringset.hpp"

#include <algorithm>
#include <string>
#include <vector>

namespace containers {

StringSet::iterator::iterator(const std::vector<std::string>::const_iterator& it)
    : it{it} {}

StringSet::iterator::reference StringSet::iterator::operator*() const {
    return *this->it;
}

StringSet::iterator::pointer StringSet::iterator::operator->() const {
    return &*this->it;
}

StringSet::iterator& StringSet::iterator::operator++() {
    ++it;
    return *this;
}

StringSet::iterator StringSet::iterator::operator++(int) {
    iterator copyIt{this->it};
    ++this->it;
    return copyIt;
}

bool operator==(const StringSet::iterator& a, const StringSet::iterator& b) {
    return a.it == b.it;
}

bool operator!=(const StringSet::iterator& a, const StringSet::iterator& b) {
    return a.it != b.it;
}

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

StringSet::iterator StringSet::begin() const noexcept {
    return iterator{set.begin()};
}

StringSet::iterator StringSet::end() const noexcept {
    return iterator{set.end()};
}
} // namespace containers
