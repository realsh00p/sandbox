#pragma once

#include <iostream>

template <typename Derived>
class ServiceABase {
public:
    void do_thing() const {
        static_cast<const Derived *>(this)->do_thing_impl();
    }

protected:
    ~ServiceABase() = default; // Ensure derived objects can be deleted properly
private:
    void do_thing_impl() const {
        // Default implementation (if needed)
    }
};

class ServiceA : public ServiceABase<ServiceA> {
public:
    void do_thing_impl() const {
        std::cout << "Real ServiceA doing its thing.\n";
    }
};

template <typename Derived>
class ServiceBBase {
public:
    void do_stuff() const {
        static_cast<const Derived *>(this)->do_stuff_impl();
    }

protected:
    ~ServiceBBase() = default;

private:
    void do_stuff_impl() const {
        // Default implementation (if needed)
    }
};

class ServiceB : public ServiceBBase<ServiceB> {
public:
    void do_stuff_impl() const {
        std::cout << "Real ServiceB doing its stuff.\n";
    }
};
