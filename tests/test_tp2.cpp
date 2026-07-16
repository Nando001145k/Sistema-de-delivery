#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>
#include "../src/product.hpp"
#include <vector>
#include <memory>


TEST_CASE("Hierarquia - Construtor Base e Derivada", "[Q1]") {
    std::unique_ptr<product> p = std::make_unique<food>(1, "Teste Comida", 10.0);
    REQUIRE(p->get_name() == "Teste Comida");
}

TEST_CASE("Polimorfismo - Calculo exato de precos dinamicos", "[Q2]") {
    std::vector<std::unique_ptr<product>> itens;
    itens.push_back(std::make_unique<food>(2, "Lanche", 100.0));
    itens.push_back(std::make_unique<beverage>(3, "Agua", 10.0));
    REQUIRE(itens[0]->calculate_price() == Catch::Approx(110.0));
    REQUIRE(itens[1]->calculate_price() == Catch::Approx(10.0));
}

TEST_CASE("Interface Pura - Validacao de Contrato", "[Q3]") {
    food refeicao(4, "Marmita", 25.0);
    const preparable* p = dynamic_cast<const preparable*>(&refeicao);
    
    REQUIRE(p != nullptr);
}