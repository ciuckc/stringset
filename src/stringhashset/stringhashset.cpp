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
    if (this->loadFactor() >= this->maximumLoadFactor) {
        rehash(this->map.size() << 1);
    }
    Node& node = this->findNodeFromIndex(data, this->getInitialNodeIndex(data));
    if (node.occupied && node.key == data) {
        return false;
    }
    node.key = data;
    node.occupied = true;
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
    Node& node = this->findNodeFromIndex(data, this->getInitialNodeIndex(data));
    return node.occupied && node.key == data;
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

float StringHashSet::loadFactor() const noexcept {
    return this->map.size() != 0 ? static_cast<float>(this->count) / this->map.size() : 0.0f;
}

size_t StringHashSet::getInitialNodeIndex(const std::string& data) const {
    std::hash<std::string> hashFunction;
    return hashFunction(data) % this->map.size();
}

StringHashSet::Node& StringHashSet::findNodeFromIndex(const std::string& data, size_t i) {
    for (auto probe = 0ul; probe < this->map.size(); ++probe) {
        if (!this->map[i].occupied || this->map[i].key == data) {
            break;
        }
        i = (i + 1) % this->map.size();
    }
    return this->map[i];
}
} // namespace containers
