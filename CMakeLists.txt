cmake_minimum_required(VERSION 4.00)

message(STATUS "CMake version: ${CMAKE_VERSION}")
# Required for "import std;" as long as its experimental in CMake
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "d0edc3af-4c50-42ea-a356-e2862fe7a444")
#set(CXXFLAGS "-stdlib=libc++")

#set(CMAKE_CXX_FLAGS_INIT "-stdlib=libc++")

# Clang 18.1.2 and newer with -stdlib=libc++ or -stdlib=libstdc++
set(CMAKE_CXX_FLAGS "${CXXFLAGS}")
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_MODULE_STD 1)

project(sample LANGUAGES CXX)

add_executable(sample src/main.cpp)

#target_compile_options(sample PUBLIC -stdlib=libstdc++)
#target_link_options(sample PUBLIC -stdlib=libstdc++)

#set(STD_IFC "C:/stl_modules/std.ifc")
#set(STD_OBJ "C:/stl_modules/std.obj")
#target_compile_options(sample PRIVATE "/reference:std=${STD_IFC}")
#target_link_options(sample PRIVATE "${STD_OBJ}")

# Helpful status messages so you can see which compiler/flags are being used.
message(STATUS "CMAKE_CXX_COMPILER: ${CMAKE_CXX_COMPILER}")
message(STATUS "CMAKE_CXX_COMPILER_ID: ${CMAKE_CXX_COMPILER_ID}")

target_compile_features(sample PRIVATE cxx_std_23)

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