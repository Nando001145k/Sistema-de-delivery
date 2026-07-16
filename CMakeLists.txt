cmake_minimum_required(VERSION 3.20)
project(Sistema_Delivery CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options(-Wall -Wextra -fsanitize=address,undefined -g)
    add_link_options(-fsanitize=address,undefined)
endif()

# Executável principal
add_executable(Sistema_Delivery
    src/main.cpp
    src/customer.cpp
    src/product.cpp
    src/order_item.cpp
    src/order.cpp
)
target_include_directories(Sistema_Delivery PRIVATE src)

# Questão 4 (A): Configuração do Catch2 via FetchContent
include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.5.2
)
FetchContent_MakeAvailable(Catch2)

add_executable(testes 
    tests/test_tp2.cpp
    src/product.cpp
    # adicione outros arquivos .cpp do domínio aqui se necessário nos testes
)
target_include_directories(testes PRIVATE src)
target_link_libraries(testes PRIVATE Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(testes)