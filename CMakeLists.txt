cmake_minimum_required(VERSION 3.20)
project(Sistema_Delivery CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options(-Wall -Wextra -fsanitize=address,undefined -g)
    add_link_options(-fsanitize=address,undefined)
endif()

add_executable(Sistema_Delivery
    src/main.cpp
    src/customer.cpp
    src/product.cpp
    src/order_item.cpp
    src/order.cpp
)

target_include_directories(Sistema_Delivery PRIVATE src)