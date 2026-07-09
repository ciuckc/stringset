#include "stringset.hpp"

namespace containers {
StringSet::StringSet() {}

StringSet::StringSet(const StringSet&) {}

StringSet::StringSet(StringSet&&) {}

StringSet& StringSet::operator=(const StringSet&) {
    return *this;
}

StringSet& StringSet::operator=(StringSet&&) {
    return *this;
}

StringSet::~StringSet() {}
} // namespace containers
