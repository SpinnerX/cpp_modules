// #include <print>
#include <array>
#include <cstdint>
import core;


int main(){
    core::buffer test_buffer;

    std::array<uint8_t, 4> bytes = {0xFF, 0xFF, 0xFF, 0xFF};

    test_buffer.write(bytes);

    return 0;
}
