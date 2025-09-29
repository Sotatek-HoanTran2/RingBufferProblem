cmake_minimum_required(VERSION 3.14)
project(ringbuffer LANGUAGES C CXX)

set(CMAKE_C_STANDARD 99)
option(CODE_COVERAGE "Enable coverage flags" OFF)

if(CODE_COVERAGE)
  message(STATUS "Enabling code coverage flags")
  if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
  endif()
  add_compile_options(--coverage -g -O0)
  add_link_options(--coverage)
endif()

add_library(ringbuffer STATIC ringbuffer.c)
target_include_directories(ringbuffer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(example main.c)
target_link_libraries(example PRIVATE ringbuffer pthread)

# GoogleTest via FetchContent
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(test_ringbuffer tests/test_ringbuffer.cpp)
target_link_libraries(test_ringbuffer PRIVATE ringbuffer GTest::gtest_main pthread)
add_test(NAME ringbuffer_tests COMMAND test_ringbuffer)
