cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

project(pp6calculator)

if(CMAKE_COMPILER_IS_GNUCXX)
	set(CMAKE_CXX_FLAGS "-std=c++0x -pedantic-errors -Wall -Werror -Wextra -Wfatal-errors -Wwrite-strings -Woverloaded-virtual -fno-nonansi-builtins -fno-gnu-keywords -fstrict-aliasing")
endif()

include_directories(PP6Lib)

add_subdirectory(PP6Lib)
add_executable(pp6calculator pp6calculator.cpp pp6menu.cpp day1.cpp)

target_link_libraries(pp6calculator pp6lib)

install(TARGETS pp6calculator DESTINATION bin)

include(CPack)
