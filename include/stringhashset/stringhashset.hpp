#pragma once

#include <cstddef>
#include <iterator>
#include <string>
#include <vector>

namespace containers {
class StringHashSet {
public:
    class iterator {
    public:
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = std::string;
        using pointer = const std::string*;
        using reference = const std::string&;

        iterator() = default;

        reference operator*() const;
        pointer operator->() const;
        iterator& operator++();
        iterator operator++(int);
        friend bool operator==(const iterator& a, const iterator& b);
        friend bool operator!=(const iterator& a, const iterator& b);

    private:
        friend class StringHashSet;

        iterator(const StringHashSet* owner, size_t index);

        void skipUnoccupied();

        const StringHashSet* owner{};
        size_t index{};
    };

    using const_iterator = iterator;

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
    iterator begin() const noexcept;
    iterator end() const noexcept;

private:
    constexpr static const float DEFAULT_MAX_LOAD_FACTOR = 0.75f;
    constexpr static const std::int64_t UNOCCUPIED = -1;

    struct Node {
        std::string key{};
        std::int64_t distanceFromIdealIndex{UNOCCUPIED};
        size_t hash{};
    };

    float loadFactor() const noexcept;
    void rehash(size_t count);
    bool insert(std::string key, size_t hash, size_t i);
    size_t indexFromHash(size_t hash) const;
    size_t findIndex(const std::string& data, size_t hash, size_t index) const;

    std::vector<Node> map{64};
    size_t count{};
    float maximumLoadFactor{DEFAULT_MAX_LOAD_FACTOR};
};
} // namespace containers
