cmake_minimum_required(VERSION 3.20)
project(Sistema_Delivery CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options(-Wall -Wextra -fsanitize=address,undefined -g)
    add_link_options(-fsanitize=address,undefined)
endif()

include(FetchContent)
FetchContent_Declare(
  json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG        v3.11.3
)
FetchContent_MakeAvailable(json)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.5.2
)
FetchContent_MakeAvailable(Catch2)

set(SOURCES
    src/customer.cpp
    src/product.cpp
    src/order_item.cpp
    src/order.cpp
    src/delivery_system.cpp
)

add_executable(Sistema_Delivery src/main.cpp ${SOURCES})
target_include_directories(Sistema_Delivery PRIVATE src)
target_link_libraries(Sistema_Delivery PRIVATE nlohmann_json::nlohmann_json)

add_executable(testes tests/test_tp3.cpp ${SOURCES})
target_include_directories(testes PRIVATE src)
target_link_libraries(testes PRIVATE Catch2::Catch2WithMain nlohmann_json::nlohmann_json)

include(CTest)
include(Catch)
catch_discover_tests(testes)