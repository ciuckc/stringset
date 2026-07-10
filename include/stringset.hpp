#pragma once

#include <cstddef>
#include <iterator>
#include <string>
#include <vector>

namespace containers {
class StringSet {
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
        friend class StringSet;

        iterator(const std::vector<std::string>::const_iterator& it);

        std::vector<std::string>::const_iterator it{};
    };

    using const_iterator = iterator;

    StringSet() = default;
    StringSet(const StringSet&) = default;
    StringSet(StringSet&&) = default;
    StringSet& operator=(const StringSet&) = default;
    StringSet& operator=(StringSet&&) = default;
    ~StringSet() = default;

    bool add(const std::string& data);
    bool remove(const std::string& data);
    bool contains(const std::string& data) const noexcept;
    iterator begin() const noexcept;
    iterator end() const noexcept;

private:
    std::vector<std::string> set;

};
} // namespace containers
