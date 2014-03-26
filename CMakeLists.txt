cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

project(pp6calculator)

if(CMAKE_COMPILER_IS_GNUCXX)
	set(CMAKE_CXX_FLAGS "-std=c++0x -pedantic-errors -g -Wall -Wextra -Wwrite-strings -Woverloaded-virtual -fno-nonansi-builtins -fno-gnu-keywords -fstrict-aliasing")
endif()

include_directories(PP6Lib)
include_directories(FileReader)

add_subdirectory(PP6Lib)
add_subdirectory(FileReader)

add_executable(pp6calculator pp6calculator.cpp pp6menu.cpp day1.cpp day2.cpp day3.cpp day4.cpp)

target_link_libraries(pp6calculator pp6lib FileReader)

install(TARGETS pp6calculator DESTINATION bin)

include(CPack)
