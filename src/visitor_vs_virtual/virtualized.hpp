#pragma once

#include <array>
#include <functional>
#include <iostream>
#include <random>

namespace virtualized {

struct Base {
    virtual void do_thing() = 0;
};

struct A : public Base {
    void do_thing() override {
        std::cout << "A::do_thing\n";
    }
};

struct B : public Base {
    void do_thing() override {
        std::cout << "B::do_thing\n";
    }
};

template <std::size_t N>
struct Run {
    Run() {
        auto gen = std::bind(std::uniform_int_distribution<>(0, 1), std::default_random_engine());
        for (auto i = 0; i < N; ++i)
            if (gen())
                array[n++] = &a.at(i);
            else
                array[n++] = &b.at(i);
    }

    std::array<A, N> a {};
    std::array<B, N> b {};
    std::array<Base *, N> array {nullptr};
    std::size_t n {0};
};

template <std::size_t N>
void run(Run<N> &run) {
    for (std::size_t i = 0; i < run.n; i++) {
        run.array.at(i)->do_thing();
    }
}

} // namespace virtualized
