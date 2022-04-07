cmake_minimum_required(VERSION 3.21)
project(library)

set(CMAKE_CXX_STANDARD 14)

add_executable(library main.c book_management.c book_management.h interface.c interface.h Login_and_register.c Login_and_register.h User.c User.h configure.h)
