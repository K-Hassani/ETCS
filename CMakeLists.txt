cmake_minimum_required(VERSION 3.5.0)
project(simulator VERSION 0.1.0 LANGUAGES C CXX)

find_package(GTest REQUIRED)

include(CTest)
include(GoogleTest)

add_executable(simulatorlibTest)
target_compile_features(simulatorlibTest PRIVATE cxx_std_17)
target_sources(simulatorlibTest PRIVATE
 hello_test.cpp
 bit_message_test.cpp
 bit_message_write_test.cpp
 sequential_bit_message_test.cpp
 token_space_test.cpp
 token_fetching_test.cpp)

target_link_libraries(simulatorlibTest PRIVATE
    GTest::gtest_main
    simulatorlib)

gtest_discover_tests(simulatorlibTest WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

