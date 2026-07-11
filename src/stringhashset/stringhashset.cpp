#include "stringhashset/stringhashset.hpp"

#include <cstddef>
#include <functional>
#include <string>

namespace containers {
StringHashSet::StringHashSet(size_t bucket_count)
    : map(bucket_count),
    count(0),
    maximumLoadFactor(0.8f) {}

bool StringHashSet::add(const std::string& data) {
    if (this->contains(data)) {
        return false;
    }
    if (this->loadFactor() >= this->maximumLoadFactor) {
        // for now just double the size
        rehash(this->map.size() << 1);
    }
    std::hash<std::string> hashFunction;
    // because of contains we hash twice which is not efficient
    // TODO: split it up
    auto i = hashFunction(data) % this->map.size();
    while (this->map[i].occupied) {
        // modulo is slow
        i = (i + 1) % this->map.size();
    }
    this->map[i].key = data;
    this->map[i].occupied = true;
    ++this->count;
    return true;
}

bool StringHashSet::remove(const std::string& data) {
    if (this->contains(data)) {
        return false;
    }
    return true;
}

bool StringHashSet::contains(const std::string& data) {
    std::hash<std::string> hashFunction;

    auto i = hashFunction(data) % this->map.size();
    for (auto probe = 0ul; probe < this->map.size(); ++probe) {
        if (!this->map[i].occupied) {
            break;
        }
        if (this->map[i].key == data) {
            return true;
        } else {
            i = (i + 1) % this->map.size();
        }
    }
    return false;
}

void StringHashSet::rehash(size_t bucketCount) {
    // division rounds down...
    size_t minBuckets = (this->count / maximumLoadFactor) + 1;
    if (bucketCount < minBuckets) {
        bucketCount = minBuckets;
    }
    std::hash<std::string> hashFunction;
    std::vector<Node> newMap(bucketCount);
    for (auto& node : this->map) {
        if (!node.occupied) {
            continue;
        }
        auto i = hashFunction(node.key) % newMap.size();
        while (newMap[i].occupied) {
            i = (i + 1) % newMap.size();
        }
        newMap[i] = std::move(node);
    }
    this->map = std::move(newMap);
}

size_t StringHashSet::size() const noexcept {
    return this->count;
}

float StringHashSet::loadFactor() const noexcept {
    return this->map.size() != 0 ? static_cast<float>(this->count) / this->map.size() : 0.0f;
}
} // namespace containers
