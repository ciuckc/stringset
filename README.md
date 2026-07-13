# StringSet

## Introduction

For this tiny project I implemented two versions of `std::set` specialized
on `std::string`.

### StringFlatSet

First one is called `StringFlatSet` and it's underlying data structure is a
sorted std::vector. This was the first implementation that I did, and
initially I thought that the `contains` operation would be significantly
faster due to CPU caching. It still beats `std::set` on search operations
on smaller data sets, but on larger data sets it becomes similar to `std::set`.
The reason why it's faster is due to the sorted nature of the vector and the
use of binary search, which is cache friendly, compared to `std::set`s red-black
tree pointer hops.

On the other hand, `add` and `remove` operations on `StringFlatSet` are extremely
slow due to the O(N) insertion and erasure time of `std::vector`. It becomes
worse and worse on bigger data sets. Here, `std::set` clocks in an easy win.

This data structure is optimal for heavy read-only workflows and where memory
footprint is important. We also get sorted key behaviour on iteration over the
set.

`StringFlatSet` was inspired by C++23s `std::flat_set`.

### StringHashSet

Second implementation is `StringHashSet` and as expected the underlying data
structure used is an unordered open addressed hash map.

## Build and run

To build, make sure you have at least CMake version 3.22.

Building:

```bash
cmake -S . -B build
cmake --build build
```

Running the tests:

```bash
ctest --output-on-failure --test-dir build
```

## Benchmarks

The benchmark numbers are shown as `millions of operations/second`.

### add

| size | StringFlatSet | StringHashSet | std::set | std::unordered_set |
| ---: | ---: | ---: | ---: | ---: |
| 8 | 17.9 | 13.6 | 19.4 | 16.6 |
| 64 | 11.19 | 8.4 | 12.5 | 14.7 |
| 512 | 3.5 | 6.5 | 5.5 | 8.2 |
| 8192 | 0.44 | 5.3 | 2.9 | 6.4 |

### contains

| size | StringFlatSet | StringHashSet | std::set | std::unordered_set |
| ---: | ---: | ---: | ---: | ---: |
| 8 | 44.08 | 26.5 | 30.07 | 40.4 |
| 64 | 27.6 | 22.4 | 14.2 | 37.9 |
| 512 | 8.9 | 20.3 | 7.7 | 28.7 |
| 8192 | 4.07 | 16.3 | 3.5 | 19.1 |

### remove

| size | StringFlatSet | StringHashSet | std::set | std::unordered_set |
| ---: | ---: | ---: | ---: | ---: |
| 8 | 7.5 | 6.4 | 6.7 | 6.8 |
| 64 | 11.03 | 14.5 | 10.6 | 14.2 |
| 512 | 2.7 | 13.1 | 6.1 | 16.2 |
| 8192 | 0.244 | 10.0 | 3.2 | 10.1 |
