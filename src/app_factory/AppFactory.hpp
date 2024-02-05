#pragma once

#include "Service.hpp"

#include <iostream>
#include <memory>
#include <string>

template <typename Derived>
class AppFactory {
public:
    template <typename T>
    std::shared_ptr<T> create_service_a() const {
        return static_cast<const Derived *>(this)->template create_service_a<T>();
    }
    template <typename T>
    std::shared_ptr<T> create_service_b() const {
        return static_cast<const Derived *>(this)->template create_service_b<T>();
    }
};

template <typename A_ = ServiceA, typename B_ = ServiceB>
class RealServicesFactory : public AppFactory<RealServicesFactory<>> {
public:
    using A = A_;
    using B = B_;

    template <typename T>
    std::shared_ptr<ServiceA> create_service_a() const {
        return std::make_shared<ServiceA>();
    }

    template <typename T>
    std::shared_ptr<ServiceB> create_service_b() const {
        return std::make_shared<ServiceB>();
    }
};
