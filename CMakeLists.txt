set(CMAKE_CXX_MODULE_STD ON)
cmake_minimum_required(VERSION 4.0)
project(Starter CXX)

set(CMAKE_CXX_STANDARD 23)

# Require Ninja or Visual Studio for modules
if(NOT CMAKE_GENERATOR MATCHES "Ninja|Visual Studio")
    message(FATAL_ERROR "C++20 modules require Ninja or Visual Studio generator")
endif()

set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD d0edc3af-4c50-42ea-a356-e2862fe7a444)

add_executable(
    ${PROJECT_NAME}
    application.cppm
)

set_property(TARGET Starter PROPERTY CXX_STANDARD 23)
set_property(TARGET Starter PROPERTY CXX_STANDARD_REQUIRED ON)

# Add module files
target_sources(${PROJECT_NAME} PUBLIC
    FILE_SET CXX_MODULES
    TYPE CXX_MODULES
    FILES
    application.cppm
)

target_compile_options(${PROJECT_NAME} PUBLIC cxx_std_23)

install(
    TARGETS Starter
    EXPORT starter_targets
    FILE_SET CXX_MODULES DESTINATION .
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)

install(
    DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles/starter.dir/
    DESTINATION modules
    FILES_MATCHING PATTERN "*.pcm"
)