#include "stringhashset/stringhashset.hpp"

#include <cstddef>

namespace containers {
StringHashSet::StringHashSet(size_t bucket_count)
    : map(bucket_count),
    count(0) {}

bool StringHashSet::add(const std::string& data) {
    (void)data;
    return true;
}

bool StringHashSet::remove(const std::string& data) {
    (void)data;
    return true;
}
bool StringHashSet::contains(const std::string& data) {
    (void)data;
    return true;
}

size_t StringHashSet::size() const noexcept {
    return this->count;
}

float StringHashSet::loadFactor() const noexcept {
    return this->map.size() != 0 ? static_cast<float>(this->count) / this->map.size() : 0.0f;
}
} // namespace containers
