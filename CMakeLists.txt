cmake_minimum_required(VERSION 3.16)

project(hazelcast-c-wrapper
        LANGUAGES C CXX)

find_package(hazelcast-cpp-client REQUIRED)

add_library(hazelcast-c-wrapper hz_wrapper.cpp hz_wrapper.h)

target_link_libraries(hazelcast-c-wrapper PRIVATE hazelcast-cpp-client::hazelcast-cpp-client)
target_include_directories(
        hazelcast-c-wrapper
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

add_subdirectory(example)