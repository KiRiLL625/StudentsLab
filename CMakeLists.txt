cmake_minimum_required(VERSION 3.24)
project(students_lab)

set(CMAKE_CXX_STANDARD 17)

add_executable(students_lab main.cpp DatabaseHandler.h DatabaseHandler.cpp Student.cpp Student.h StudentUtil.h StudentUtil.cpp InputFunctions.h InputFunctions.cpp)
