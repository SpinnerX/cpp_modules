module;

#include <print>
import test2;

export module test;

export void print_hello() {
    std::println("Hello, World!");
    std::println("Square = {}", square(1, 2));
}


namespace atlas {

    namespace internal {
        void poll_start(auto* p_instance, const auto& p_callback) {
        }
    };

    export void register_start(auto* p_instance, const auto& p_callback) {
        internal::poll_start(p_instance, p_callback);
    }
};