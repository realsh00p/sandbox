#include "virtualized.hpp"
#include "visitor.hpp"

#include <benchmark/benchmark.h>

static void BM_virtualized(benchmark::State &state) {
    for (auto _ : state)
        virtualized::run();
}
BENCHMARK(BM_virtualized);

static void BM_visitor(benchmark::State &state) {
    for (auto _ : state)
        visitor::run();
}
BENCHMARK(BM_visitor);

BENCHMARK_MAIN();
