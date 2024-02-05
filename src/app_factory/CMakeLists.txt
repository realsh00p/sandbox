set(target app_factory)

add_executable(${target})

target_sources(${target}
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/App.hpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test.cpp
)

target_link_libraries(${target}
    PRIVATE GTest::gtest GTest::gtest_main GTest::gmock
)
