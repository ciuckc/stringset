#pragma once

#include <vector>

namespace containers {
class StringHashSet {
public:
    StringHashSet(size_t bucket_count);

private:
    struct Node {
        std::string key;
        bool occupied;
    };

    std::vector<Node> map;
};
} // namespace containers
