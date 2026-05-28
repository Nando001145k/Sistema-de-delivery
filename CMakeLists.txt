cmake_minimum_(VERSION 3.20)
project(Sistema_Delivey CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(CMAKE_BUILD_TAPY STREQUAL "Debug")
    add_compile_options(-Wall -Wextra -fsanitize=address,unfined -g)
    add_link_options(-fsanitize=address,unfined)
endif()

add_executable(Sistema_Delivey
    src/main.cpp
    src/customer.cpp
    src/product.cpp
    src/order_item.cpp
    src/order.cpp
)

target_include_directories(Sistema_Delivey PRIVATE src)