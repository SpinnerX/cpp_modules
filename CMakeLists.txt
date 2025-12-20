cmake_minimum_required(VERSION 4.0)
project(Starter CXX)

set(CMAKE_CXX_STANDARD 23)

# Require Ninja or Visual Studio for modules
if(NOT CMAKE_GENERATOR MATCHES "Ninja|Visual Studio")
    message(FATAL_ERROR "C++20 modules require Ninja or Visual Studio generator")
endif()

# set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD d0edc3af-4c50-42ea-a356-e2862fe7a444)

add_executable(
    ${PROJECT_NAME}
    application.cpp
)

target_sources(${PROJECT_NAME} PUBLIC
    FILE_SET CXX_MODULES
    TYPE CXX_MODULES
    FILES
    core/core.cppm
    core/buffer.cppm
)

target_include_directories(${PROJECT_NAME} PUBLIC ./)

generate_compile_commands()

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_23)