#pragma once

#include <cstdint>

inline std::uint8_t rearrange_bits_inline(std::uint8_t originalByte) {
    // clang-format off
    return ((originalByte >> 0) & 0x01) |
           ((originalByte >> 1) & 0x01) << 4 |
           ((originalByte >> 2) & 0x01) << 1 |
           ((originalByte >> 3) & 0x01) << 5 |
           ((originalByte >> 4) & 0x01) << 2 |
           ((originalByte >> 5) & 0x01) << 6 |
           ((originalByte >> 6) & 0x01) << 3 |
           ((originalByte >> 7) & 0x01) << 7;
    // clang-format on
}

const std::uint8_t rearrangeTable[] = {0, 4, 1, 5, 2, 6, 3, 7};

inline std::uint8_t rearrange_bits_lookup(std::uint8_t originalByte) {
    std::uint8_t rearrangedByte = 0;
    for (int i = 0; i < 8; ++i) {
        rearrangedByte |= ((originalByte >> i) & 0x01) << rearrangeTable[i];
    }
    return rearrangedByte;
}
