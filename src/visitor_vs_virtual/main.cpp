#include "virtualized.hpp"
#include "visitor.hpp"

#include <benchmark/benchmark.h>

static constexpr auto N = 65535;

static void BM_virtualized(benchmark::State &state) {
    static virtualized::Run<N> run;
    for (auto _ : state)
        virtualized::run(run);
}
BENCHMARK(BM_virtualized);

static void BM_visitor(benchmark::State &state) {
    static visitor::Run<N> run;
    for (auto _ : state)
        visitor::run(run);
}
BENCHMARK(BM_visitor);

BENCHMARK_MAIN();
