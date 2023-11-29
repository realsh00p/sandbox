#include "visitor.hpp"

#include <array>
#include <iostream>
#include <variant>

namespace visitor {

struct A {
    void do_thing(int datum = 0) {
        asm volatile("" : "+r"(datum));
    }
};

struct B {
    void do_thing(int datum = 0) {
        asm volatile("" : "+r"(datum));
    }
};

template <typename T>
void visitor(T &&arg) {
    using t = std::decay_t<decltype(arg)>;
    if constexpr (!std::is_same_v<t, std::monostate>)
        arg.t::do_thing();
}

void run() {
    using Variant = std::variant<std::monostate, A, B>;

    std::array<Variant, 1024> array {};
    std::size_t n {0};

    array[n++] = A();
    array[n++] = A();
    array[n++] = B();
    array[n++] = B();

    for (std::size_t i = 0; i < n; i++) {
        std::visit([](auto &&arg) { visitor(arg); }, array.at(i));
    }
}

} // namespace visitor
