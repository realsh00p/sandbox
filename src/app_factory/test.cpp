#include "App.hpp"
#include "Service.hpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(Test, use_real_a_real_b) {
    RealServicesFactory factory;
    App app(factory);
    app.run();
}

class MockServiceA : public ServiceABase<MockServiceA> {
public:
    MOCK_METHOD(void, do_thing_impl, (), (const));
};

class MockServiceB : public ServiceBBase<MockServiceB> {
public:
    MOCK_METHOD(void, do_stuff_impl, (), (const));
};

// Factory for mock services

class MockServicesFactory : public AppFactory<MockServicesFactory> {
public:
    using A = MockServiceA;
    using B = MockServiceB;

    MOCK_METHOD(std::shared_ptr<MockServiceA>, create_service_a, (), (const));
    MOCK_METHOD(std::shared_ptr<MockServiceB>, create_service_b, (), (const));

    template <typename T>
    std::shared_ptr<MockServiceA> create_service_a() const {
        return create_service_a();
    }

    template <typename T>
    std::shared_ptr<MockServiceB> create_service_b() const {
        return create_service_b();
    }
};

TEST(Test, use_real_a_mock_b) {
    auto service_a = std::make_shared<::testing::StrictMock<MockServiceA>>();
    auto service_b = std::make_shared<::testing::StrictMock<MockServiceB>>();

    EXPECT_CALL(*service_b.get(), do_stuff_impl).WillOnce(::testing::Invoke([]() {
        std::cerr << "MockServiceB::do_stuff()\n";
    }));

    ::testing::StrictMock<MockServicesFactory> factory;
    EXPECT_CALL(factory, create_service_a).WillOnce(::testing::Return(service_a));
    EXPECT_CALL(factory, create_service_b).WillOnce(::testing::Return(service_b));

    App app(factory);
    app.run();
}
