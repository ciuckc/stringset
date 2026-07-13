#include "stringhashset/stringhashset.hpp"

#include <cstddef>
#include <functional>
#include <string>
#include <utility>

namespace containers {
StringHashSet::iterator::iterator(const StringHashSet* owner, size_t index)
    : owner(owner),
    index(index) {
    this->skipUnoccupied();
}

void StringHashSet::iterator::skipUnoccupied() {
    while (this->index < this->owner->map.size() &&
        this->owner->map[this->index].distanceFromIdealIndex == StringHashSet::UNOCCUPIED) {
        ++this->index;
    }
}

StringHashSet::iterator::reference StringHashSet::iterator::operator*() const {
    return this->owner->map[this->index].key;
}

StringHashSet::iterator::pointer StringHashSet::iterator::operator->() const {
    return &this->owner->map[this->index].key;
}

StringHashSet::iterator& StringHashSet::iterator::operator++() {
    ++this->index;
    this->skipUnoccupied();
    return *this;
}

StringHashSet::iterator StringHashSet::iterator::operator++(int) {
    iterator copy{*this};
    ++(*this);
    return copy;
}

bool operator==(const StringHashSet::iterator& a, const StringHashSet::iterator& b) {
    return a.owner == b.owner && a.index == b.index;
}

bool operator!=(const StringHashSet::iterator& a, const StringHashSet::iterator& b) {
    return !(a == b);
}

StringHashSet::StringHashSet(size_t bucket_count)
    : map(bucket_count),
    count(0),
    maximumLoadFactor(this->DEFAULT_MAX_LOAD_FACTOR) {}

bool StringHashSet::add(const std::string& data) {
    if (this->loadFactor() >= this->maximumLoadFactor) {
        rehash(this->map.size() << 1);
    }
    size_t hash = std::hash<std::string>{}(data);
    if (!this->insert(data, hash, this->indexFromHash(hash))) {
        return false;
    }
    ++this->count;
    return true;
}

bool StringHashSet::remove(const std::string& data) {
    size_t hash = std::hash<std::string>{}(data);
    size_t index = this->findIndex(data, hash, this->indexFromHash(hash));
    if (this->map[index].distanceFromIdealIndex == this->UNOCCUPIED ||
        this->map[index].hash != hash || this->map[index].key != data) {
        return false;
    }
    size_t next = (index + 1) % this->map.size();
    while (this->map[next].distanceFromIdealIndex > 0) {
        this->map[index] = std::move(this->map[next]);
        --this->map[index].distanceFromIdealIndex;
        index = next;
        next = (next + 1) % this->map.size();
    }
    this->map[index].distanceFromIdealIndex = this->UNOCCUPIED;
    --this->count;
    return true;
}

bool StringHashSet::contains(const std::string& data) {
    size_t hash = std::hash<std::string>{}(data);
    size_t index = this->findIndex(data, hash, this->indexFromHash(hash));
    return this->map[index].distanceFromIdealIndex != this->UNOCCUPIED &&
        this->map[index].hash == hash && this->map[index].key == data;
}

void StringHashSet::rehash(size_t bucketCount) {
    // division rounds down...
    size_t minBuckets = (this->count / maximumLoadFactor) + 1;
    if (bucketCount < minBuckets) {
        bucketCount = minBuckets;
    }
    std::vector<Node> oldMap = std::move(this->map);
    this->map = std::vector<Node>(bucketCount);
    for (auto& node : oldMap) {
        if (node.distanceFromIdealIndex == this->UNOCCUPIED) {
            continue;
        }
        this->insert(std::move(node.key), node.hash, this->indexFromHash(node.hash));
    }
}

float StringHashSet::loadFactor() const noexcept {
    return this->map.size() != 0 ? static_cast<float>(this->count) / this->map.size() : 0.0f;
}

bool StringHashSet::insert(std::string key, size_t hash, size_t i) {
    std::int64_t distance = 0;
    while (true) {
        Node& node = this->map[i];
        if (node.distanceFromIdealIndex == this->UNOCCUPIED) {
            node.key = std::move(key);
            node.hash = hash;
            node.distanceFromIdealIndex = distance;
            return true;
        }
        if (node.hash == hash && node.key == key) {
            return false;
        }
        if (node.distanceFromIdealIndex < distance) {
            std::swap(node.key, key);
            std::swap(node.hash, hash);
            std::swap(node.distanceFromIdealIndex, distance);
        }
        i = (i + 1) % this->map.size();
        ++distance;
    }
}

size_t StringHashSet::indexFromHash(size_t hash) const {
    return hash % this->map.size();
}

size_t StringHashSet::findIndex(const std::string& data, size_t hash, size_t index) const {
    auto distance = 0l;
    while (this->map[index].distanceFromIdealIndex != this->UNOCCUPIED) {
        if (this->map[index].distanceFromIdealIndex < distance ||
            (this->map[index].hash == hash && this->map[index].key == data)) {
            break;
        }
        index = (index + 1) % this->map.size();
        ++distance;
    }
    return index;
}
StringHashSet::iterator StringHashSet::begin() const noexcept {
    return iterator(this, 0);
}

StringHashSet::iterator StringHashSet::end() const noexcept {
    return iterator(this, this->map.size());
}

} // namespace containers
