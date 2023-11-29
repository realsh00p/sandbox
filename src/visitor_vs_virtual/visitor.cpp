#include "visitor.hpp"

namespace visitor {

template <typename T>
void visitor(T &&arg) {
    using t = std::decay_t<decltype(arg)>;
    if constexpr (!std::is_same_v<t, std::monostate>)
        arg.t::do_thing();
}

void run(Run &run) {
    for (std::size_t i = 0; i < run.n; i++) {
        std::visit([](auto &&arg) { visitor(arg); }, run.array.at(i));
    }
}

} // namespace visitor
