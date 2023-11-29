set(target visitor_vs_virtual)

add_executable(${target})

target_sources(${target}
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/virtualized.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/virtualized.hpp
            ${CMAKE_CURRENT_SOURCE_DIR}/visitor.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/visitor.hpp
            ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

target_link_libraries(${target}
    PRIVATE benchmark::benchmark
)
