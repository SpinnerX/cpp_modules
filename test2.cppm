module;

#include <cstdint>
#include <cmath>

export module test2;

export uint32_t square(uint32_t p_value1, uint32_t p_value2) {
    return (p_value1 * p_value2) * 2;
}