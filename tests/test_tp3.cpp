#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>

#include "generic_registry.hpp"
#include "domain_exceptions.hpp"
#include "repository.hpp"
#include "delivery_system.hpp"

TEST_CASE("Q1 - Generic Registry e Concept calculable", "[Q1]") {
    generic_registry<food> reg;
    reg.add(food(1, "Pizza", 40.0));
    REQUIRE(reg.size() == 1);
    REQUIRE(reg.calculate_total_sum() == Catch::Approx(44.0)); 
}

TEST_CASE("Q2 - Excecoes e std::optional", "[Q2]") {
    memory_repository repo;
    delivery_system sys(repo);

    REQUIRE_THROWS_AS(sys.add_product(nullptr, "Erro"), domain_error);
    REQUIRE_FALSE(sys.find_product_by_id(999).has_value());
}

TEST_CASE("Q4 - DIP e Memory Repository", "[Q4]") {
    memory_repository mem_repo;
    delivery_system sys(mem_repo);

    sys.add_product(std::make_unique<food>(10, "Lanche Memoria", 20.0), "FastFood");
    sys.save_state();

    json loaded = mem_repo.load();
    REQUIRE(loaded["version"] == 1);
    REQUIRE(loaded["items"].size() == 1);
}

TEST_CASE("Q3 - Concorrencia e Algoritmos STL", "[Q3]") {
    memory_repository repo;
    delivery_system sys(repo);

    sys.add_product(std::make_unique<beverage>(1, "Agua", 5.0), "Bebida");
    sys.add_product(std::make_unique<food>(2, "Prato Feito", 25.0), "Refeicao");

    REQUIRE(sys.count_products_above_price(10.0) == 1);
    REQUIRE(sys.process_prices_in_parallel() == Catch::Approx(32.5)); 
}
