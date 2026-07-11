#pragma once

#include <vector>

namespace containers {
class StringHashSet {
public:
    StringHashSet(size_t bucket_count);
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

private:
    struct Node {
        std::string key{};
        bool occupied{false};
    };

    std::vector<Node> map{};
    size_t count{};
};
} // namespace containers
