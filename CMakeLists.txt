cmake_minimum_required(VERSION 2.8)
project(text-based-rpg)

set(CMAKE_CXX_STANDARD 14)

add_executable(text-based-rpg main.cpp)

add_executable(tests unit_test.cpp)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
