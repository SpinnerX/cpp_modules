import os
from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout, CMakeDeps
import os

class StarterConanRecipe(ConanFile):
    name = "example"
    version = "1.0"
    settings = "os", "compiler", "build_type", "arch"
    export_source = "CMakeLists.txt", "Application.cpp"

    # Putting all of your build-related dependencies here
    def build_requirements(self):
        # self.tool_requires("make/4.4.1")
        self.tool_requires("cmake/4.1.2")
        self.tool_requires("ninja/1.13.1")
        self.tool_requires("engine3d-cmake-utils/4.0")

    # Putting all of your packages here
    def requirements(self):
        pass

    def generate(self):
        tc = CMakeToolchain(self)
        tc.generator = "Ninja"
        tc.cache_variables["CMAKE_CXX_SCAN_FOR_MODULES"] = True
        tc.generate()

        deps = CMakeDeps(self)
        deps.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()
    
    def layout(self):
        cmake_layout(self)
