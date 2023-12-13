#include "rearrange_bits.hpp"

#include <array>
#include <bitset>
#include <iostream>
#include <random>

#include <benchmark/benchmark.h>

template <std::size_t N>
std::array<std::uint8_t, N> generateRandomArray() {
    std::array<std::uint8_t, N> randomArray;

    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<std::uint8_t> distribution(0, std::numeric_limits<std::uint8_t>::max());

    for (std::size_t i = 0; i < N; ++i) {
        randomArray[i] = distribution(generator);
    }

    return randomArray;
}

static auto bytes = generateRandomArray<512>();

static void BM_rearrange_bits_inline(benchmark::State &state) {
    for (auto _ : state)
        for (auto byte : bytes)
            std::cout << std::bitset<8>(rearrange_bits_inline(byte)) << " ";
    std::cout << "\n";
}
BENCHMARK(BM_rearrange_bits_inline);

static void BM_rearrange_bits_lookup(benchmark::State &state) {
    for (auto _ : state)
        for (auto byte : bytes)
            std::cout << std::bitset<8>(rearrange_bits_lookup(byte)) << " ";
    std::cout << "\n";
}
BENCHMARK(BM_rearrange_bits_lookup);

BENCHMARK_MAIN();
