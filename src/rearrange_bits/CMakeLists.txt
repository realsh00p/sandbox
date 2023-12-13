set(target rearrange_bits)

add_executable(${target})

target_sources(${target}
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/rearrange_bits.hpp
            ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

target_link_libraries(${target}
    PRIVATE benchmark::benchmark
)
