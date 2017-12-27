cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project("Random Utils")

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)
enable_testing()
include(unit_tests)
include(lib_extensions)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
    "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(warnings "-Wall -Wextra -Werror")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    set(warnings "/W4 /WX /EHsc")
endif()
if (NOT CONFIGURED_ONCE)
    set(CMAKE_CXX_FLAGS "${warnings}"
    CACHE STRING "Flags used by the compiler during all build types." FORCE)
    set(CMAKE_C_FLAGS   "${warnings}"
    CACHE STRING "Flags used by the compiler during all build types." FORCE)
endif()

include_directories(include)
add_subdirectory(tests)
file(GLOB SOURCES "src/*.cpp")
add_library(random_utils SHARED ${SOURCES})
set_property(TARGET random_utils PROPERTY CXX_STANDARD 14)
