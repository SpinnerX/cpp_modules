cmake_minimum_required(VERSION 4.0)
project(Starter CXX)

set(CMAKE_CXX_STANDARD 23)

# Require Ninja or Visual Studio for modules
if(NOT CMAKE_GENERATOR MATCHES "Ninja|Visual Studio")
    message(FATAL_ERROR "C++20 modules require Ninja or Visual Studio generator")
endif()

set(CMAKE_CXX_SCAN_FOR_MODULES ON)
set(CMAKE_EXPERIMENTAL_EXPORT_PACKAGE_DEPENDENCIES "1942b4fa-b2c5-4546-9385-83f254070067")

# add_library(test_module test.cppm)

add_executable(
    ${PROJECT_NAME}
    application.cpp
)

generate_compile_commands()

target_sources(${PROJECT_NAME} PUBLIC
    FILE_SET CXX_MODULES
    TYPE CXX_MODULES
    FILES
    test.cppm
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_23)