#include "stringhashset/stringhashset.hpp"

#include <cstddef>

namespace containers {
StringHashSet::StringHashSet(size_t bucket_count)
    : map(bucket_count) {}
}
