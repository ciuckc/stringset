#pragma once

#include <vector>

namespace containers {
class StringHashSet {
public:
    explicit StringHashSet(size_t bucket_count);
    StringHashSet() = default;
    StringHashSet(const StringHashSet&) = default;
    StringHashSet& operator=(const StringHashSet&) = default;
    StringHashSet(StringHashSet&&) = default;
    StringHashSet& operator=(StringHashSet&&) = default;
    ~StringHashSet() = default;

    bool add(const std::string& data);
    bool remove(const std::string& data);
    bool contains(const std::string& data);

private:
    struct Node {
        std::string key{};
        bool occupied{false};
    };

    constexpr const static float DEFAULT_MAX_LOAD_FACTOR = 0.75f;

    float loadFactor() const noexcept;
    void rehash(size_t count);
    size_t getInitialNodeIndex(const std::string& data) const;
    Node& findNodeFromIndex(const std::string& data, size_t i);

    std::vector<Node> map{64};
    size_t count{};
    float maximumLoadFactor{DEFAULT_MAX_LOAD_FACTOR};
};
} // namespace containers
