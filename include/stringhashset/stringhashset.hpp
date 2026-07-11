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
    size_t size() const noexcept;
    float loadFactor() const noexcept;
    void rehash(size_t count);

private:
    struct Node {
        std::string key{};
        bool occupied{false};
    };

    std::vector<Node> map{64};
    size_t count{};
    float maximumLoadFactor{0.8};
};
} // namespace containers
