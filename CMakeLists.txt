cmake_minimum_required(VERSION 3.23)
project(test C)

set(CMAKE_C_STANDARD 99)

add_executable(test main.c main2.c main3.c main4.c main5.c exit_codes.h main6.c)

target_link_libraries(test ws2_32)

target_compile_options(test PRIVATE -O0 -fno-stack-protector -g)