#include "virtualized.hpp"
#include "visitor.hpp"

#include <benchmark/benchmark.h>

static void BM_virtualized(benchmark::State &state) {
    virtualized::Run run;
    for (auto _ : state)
        virtualized::run(run);
}
BENCHMARK(BM_virtualized);

static void BM_visitor(benchmark::State &state) {
    visitor::Run run;
    for (auto _ : state)
        visitor::run(run);
}
BENCHMARK(BM_visitor);

BENCHMARK_MAIN();
