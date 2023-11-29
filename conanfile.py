from conans import ConanFile, CMake

import shutil
import os
import glob

class Sandbox(ConanFile):
    name = "sandbox"
    version = "0.0.1"

    exports = "*"
    settings = "os", "compiler", "build_type", "arch"
    generators = "cmake", "cmake_find_package"

    def requirements(self):
        self.requires("boost/1.78.0")
        self.requires("gtest/1.14.0")
        self.requires("benchmark/1.8.3")

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
        self.run_unit_tests(cmake)

    def run_unit_tests(self, cmake):
        errors=[]
        for f in glob.glob(cmake.build_dir + '/**/*_unit_test', recursive=True):
            self.output.info("running unit test: " + f)
            try:
                self.run(f)
            except:
                errors.append(f)
        if len(errors):
            raise f"unit tests failed: {errors}"
