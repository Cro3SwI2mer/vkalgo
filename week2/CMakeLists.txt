cmake_minimum_required(VERSION 3.11 )
project(week2 VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Compiler
set(CMAKE_CXX_COMPILER_ID "GNU")

# WEEK_2
set(WEEK_2_SOURCE_FILES
    week2.hpp week2.cpp
    )

add_library(
            week2_lib STATIC
            ${WEEK_2_SOURCE_FILES}
            )

# Compiler Options
target_compile_options(week2_lib PRIVATE -Wall -Wextra)
target_compile_options(week2_lib PRIVATE -Wno-sign-compare)
target_compile_options(week2_lib PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-Werror=implicit-function-declaration>)

option(TREAT_WARNINGS_AS_ERRORS "DO NOT allow to build week2_lib with warnings" OFF)
if(TREAT_WARNINGS_AS_ERRORS)
  message(STATUS "Build week2_lib without warnings")
  target_compile_options(week2_lib PRIVATE -Werror)
else()
  message(STATUS "Build week2_lib with warnings")
endif()

# Compiler specific warnings
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  target_compile_options(week2_lib PRIVATE -Wshadow=compatible-local)
  target_compile_options(week2_lib PRIVATE -Wduplicated-branches)
  target_compile_options(week2_lib PRIVATE -Wduplicated-cond)
  # False positives
  target_compile_options(week2_lib PRIVATE -Wno-array-bounds)
  target_compile_options(week2_lib PRIVATE -Wno-maybe-uninitialized)
  target_compile_options(week2_lib PRIVATE -Wno-restrict)
  target_compile_options(week2_lib PRIVATE -Wno-stringop-overflow -Wno-stringop-overread)
elseif(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  target_compile_options(week2_lib PRIVATE -Wshadow-uncaptured-local)
  target_compile_options(week2_lib PRIVATE -Wloop-analysis)
  target_compile_options(week2_lib PRIVATE -Wno-self-assign-overloaded)
endif()

# Executable
add_executable(test test.cpp)
target_link_libraries(test week2_lib)
