cmake_minimum_required(VERSION 3.16)

project(my-c-project 
        LANGUAGES C)

add_executable(main main.c)

target_link_libraries(main PRIVATE hazelcast-c-wrapper)
