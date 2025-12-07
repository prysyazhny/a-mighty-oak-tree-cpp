cmake_minimum_required(VERSION 3.24)

project(a_mighty_oak_tree)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.8.1
)

FetchContent_MakeAvailable(Catch2)

add_executable(node_test tests/node_test.cpp src/node.hpp src/squirrel.hpp)
add_executable(main main.cpp src/node.hpp src/squirrel.hpp)

target_link_libraries(node_test PRIVATE Catch2::Catch2WithMain)
