#pragma once

#include <array>
#include <iostream>
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

struct Run {
    Run() {
        for (auto i = 0; i < 256; ++i) {
            array[n++] = A();
        }
        for (auto i = 0; i < 256; ++i) {
            array[n++] = B();
        }
    }

    using Variant = std::variant<std::monostate, A, B>;

    std::array<Variant, 1024> array {};
    std::size_t n {0};
};

void run(Run &run);

} // namespace visitor
