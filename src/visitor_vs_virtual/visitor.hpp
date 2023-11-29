#pragma once

#include <array>
#include <functional>
#include <iostream>
#include <random>
#include <variant>

namespace visitor {

struct A {
    void do_thing() {
        std::cout << "A::do_thing\n";
    }
};

struct B {
    void do_thing() {
        std::cout << "B::do_thing\n";
    }
};

template <std::size_t N>
struct Run {
    Run() {
        auto gen = std::bind(std::uniform_int_distribution<>(0, 1), std::default_random_engine());
        for (auto i = 0; i < N; ++i)
            if (gen())
                array[n++] = A();
            else
                array[n++] = B();
    }

    using Variant = std::variant<std::monostate, A, B>;

    std::array<Variant, N> array {};
    std::size_t n {0};
};

template <typename T>
void visitor(T &&arg) {
    using t = std::decay_t<decltype(arg)>;
    if constexpr (!std::is_same_v<t, std::monostate>)
        arg.t::do_thing();
}

template <std::size_t N>
void run(Run<N> &run) {
    for (std::size_t i = 0; i < run.n; i++) {
        std::visit([](auto &&arg) { visitor(arg); }, run.array.at(i));
    }
}

} // namespace visitor
