#include <benchmark/benchmark.h>

#include <algorithm>
#include <random>
#include <string>
#include <unordered_set>
#include <vector>

#include "stringhashset/stringhashset.hpp"

namespace {
std::vector<std::string> makeStrings(int64_t n) {
    std::vector<std::string> strings;
    strings.reserve(n);
    for (int i = 0; i < n; ++i) {
        strings.push_back(std::to_string(i));
    }
    std::mt19937 rng(777);
    std::shuffle(strings.begin(), strings.end(), rng);
    return strings;
}

void BM_StringHashSet_add(benchmark::State& state) {
    const auto strings = makeStrings(state.range(0));
    for (auto _ : state) {
        containers::StringHashSet set;
        for (const auto& s : strings) {
            benchmark::DoNotOptimize(set.add(s));
        }
    }
    state.SetItemsProcessed(state.iterations() * strings.size());
}

void BM_StringHashSet_contains(benchmark::State& state) {
    const auto strings = makeStrings(state.range(0));
    containers::StringHashSet set;
    for (const auto& s : strings) {
        set.add(s);
    }
    for (auto _ : state) {
        for (const auto& s : strings) {
            benchmark::DoNotOptimize(set.contains(s));
        }
    }
    state.SetItemsProcessed(state.iterations() * strings.size());
}

void BM_StdUnorderedSet_contains(benchmark::State& state) {
    const auto strings = makeStrings(state.range(0));
    std::unordered_set<std::string> set{64};
    for (const auto& s : strings) {
        set.insert(s);
    }
    for (auto _ : state) {
        for (const auto& s : strings) {
            benchmark::DoNotOptimize(set.find(s) != set.end());
        }
    }
    state.SetItemsProcessed(state.iterations() * strings.size());
}

void BM_StdUnorderedSet_add(benchmark::State& state) {
    const auto strings = makeStrings(state.range(0));
    for (auto _ : state) {
        std::unordered_set<std::string> set{64};
        for (const auto& s : strings) {
            benchmark::DoNotOptimize(set.insert(s));
        }
    }
    state.SetItemsProcessed(state.iterations() * strings.size());
}
} // namespace

BENCHMARK(BM_StringHashSet_add)->Range(8, 8 << 10);

BENCHMARK(BM_StringHashSet_contains)->Range(8, 8 << 10);

BENCHMARK(BM_StdUnorderedSet_contains)->Range(8, 8 << 10);

BENCHMARK(BM_StdUnorderedSet_add)->Range(8, 8 << 10);
