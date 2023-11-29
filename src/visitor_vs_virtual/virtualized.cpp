#include "virtualized.hpp"

#include <array>
#include <iostream>

namespace virtualized {

struct Base {
    virtual void do_thing(int datum = 0) = 0;
};

struct A : public Base {
    void do_thing(int datum) override {
        asm volatile("" : "+r"(datum));
    }
};

struct B : public Base {
    void do_thing(int datum) override {
        asm volatile("" : "+r"(datum));
    }
};

void run() {

    std::array<A, 1024> a {};
    std::array<B, 1024> b {};
    std::array<Base *, 1024> array {nullptr};
    std::size_t n {0};

    array[n++] = &a.at(0);
    array[n++] = &a.at(1);
    array[n++] = &b.at(0);
    array[n++] = &b.at(1);

    for (std::size_t i = 0; i < n; i++) {
        array.at(i)->do_thing();
    }
}

} // namespace virtualized