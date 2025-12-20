module;

#include <print>
#include <span>
#include <cstdint>

export module core:buffer;

export namespace core {
    class buffer {
    public:
        buffer() = default;

        void write(const std::span<const uint8_t> p_data) {
            for(uint32_t i = 0; i < p_data.size(); i++) {
                std::println("I = {}", i); 
            }
        }
    };
};