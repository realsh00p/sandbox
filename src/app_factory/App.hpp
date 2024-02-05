#pragma once

#include "AppFactory.hpp"

#include <iostream>
#include <memory>
#include <string>

template <typename Factory>
class App {
    Factory &factory_;

public:
    App(Factory &factory) : factory_(factory) {
    }

    void run() {
        auto serviceA = factory_.template create_service_a<typename Factory::A>();
        auto serviceB = factory_.template create_service_b<typename Factory::B>();
    }
};
