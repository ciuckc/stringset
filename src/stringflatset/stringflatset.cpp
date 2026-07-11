#include "stringflatset/stringflatset.hpp"

#include <algorithm>
#include <string>
#include <vector>

namespace containers {

StringFlatSet::iterator::iterator(const std::vector<std::string>::const_iterator& it)
    : it{it} {}

StringFlatSet::iterator::reference StringFlatSet::iterator::operator*() const {
    return *this->it;
}

StringFlatSet::iterator::pointer StringFlatSet::iterator::operator->() const {
    return &*this->it;
}

StringFlatSet::iterator& StringFlatSet::iterator::operator++() {
    ++it;
    return *this;
}

StringFlatSet::iterator StringFlatSet::iterator::operator++(int) {
    iterator copyIt{this->it};
    ++this->it;
    return copyIt;
}

bool operator==(const StringFlatSet::iterator& a, const StringFlatSet::iterator& b) {
    return a.it == b.it;
}

bool operator!=(const StringFlatSet::iterator& a, const StringFlatSet::iterator& b) {
    return a.it != b.it;
}

bool StringFlatSet::contains(const std::string& data) const noexcept {
    auto it = std::lower_bound(this->set.begin(), this->set.end(), data);
    return it != this->set.end() && *it == data;
}

bool StringFlatSet::add(const std::string& data) {
    auto it = std::lower_bound(this->set.begin(), this->set.end(), data);
    if (it != this->set.end() && *it == data) {
        return false;
    }
    set.insert(it, data);
    return true;
}

bool StringFlatSet::remove(const std::string& data) {
    auto it = std::lower_bound(this->set.begin(), this->set.end(), data);
    if (it == this->set.end() || *it != data) {
        return false;
    }
    set.erase(it);
    return true;
}

StringFlatSet::iterator StringFlatSet::begin() const noexcept {
    return iterator{set.begin()};
}

StringFlatSet::iterator StringFlatSet::end() const noexcept {
    return iterator{set.end()};
}
} // namespace containers
