#pragma once

#include <array>
#include <iostream>

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

struct Run {
    Run() {
        for (auto i = 0; i < 256; ++i) {
            array[n++] = &a.at(i);
        }
        for (auto i = 0; i < 256; ++i) {
            array[n++] = &b.at(i);
        }
    }

    std::array<A, 1024> a {};
    std::array<B, 1024> b {};
    std::array<Base *, 1024> array {nullptr};
    std::size_t n {0};
};

void run(Run &run);

} // namespace virtualized
