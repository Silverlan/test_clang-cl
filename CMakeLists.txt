cmake_minimum_required(VERSION 3.20)
project(sample LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(sample src/main.cpp)

# Helpful status messages so you can see which compiler/flags are being used.
message(STATUS "CMAKE_CXX_COMPILER: ${CMAKE_CXX_COMPILER}")
message(STATUS "CMAKE_CXX_COMPILER_ID: ${CMAKE_CXX_COMPILER_ID}")

if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  message(STATUS "Detected Clang family compiler (this may be clang-cl on Windows)")
endif()

if(MSVC)
  message(STATUS "MSVC generator / MSVC-like environment detected")
endif()

# Example: add compile options commonly needed with clang-cl if you want
if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang" AND MSVC)
  # clang-cl understands MSVC flags; enable warnings similarly
  target_compile_options(sample PRIVATE /W4)
endif()