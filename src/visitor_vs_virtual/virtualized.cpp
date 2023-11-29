#include "virtualized.hpp"

namespace virtualized {

void run(Run &run) {
    for (std::size_t i = 0; i < run.n; i++) {
        run.array.at(i)->do_thing();
    }
}

} // namespace virtualized
