#include "generic_registry.hpp"
#include "domain_exceptions.hpp"
#include "repository.hpp"
#include "delivery_system.hpp"
#include <iostream>

int main() {
    std::cout << "=== TP3: SISTEMA DELIVERY (C++20) ===\n\n";
    std::cout << "[ Questao 1 (A/D) - Template Generic Registry com Concept ]\n";
    generic_registry<food> food_reg;
    food_reg.add(food(101, "Pizza Pepperoni", 50.0));
    food_reg.add(food(102, "Hamburguer Duplo", 30.0));

    generic_registry<beverage> beverage_reg;
    beverage_reg.add(beverage(103, "Suco Natural", 10.0));

    std::cout << "Total no registro de comidas: R$ " << food_reg.calculate_total_sum() << "\n";
    std::cout << "Total no registro de bebidas: R$ " << beverage_reg.calculate_total_sum() << "\n\n";
    std::cout << "[ Questao 1 (B) - CRTP Instancias Vivas ]\n";
    std::cout << "Instancias de product ativas: " << product::alive() << "\n\n";

    json_repository prod_repo("sistema_estado.json");
    delivery_system sys(prod_repo);

    sys.add_product(std::make_unique<food>(201, "Lasanha Bolonhesa", 40.0), "Massa");
    sys.add_product(std::make_unique<beverage>(202, "Refrigerante Cola", 8.0), "Bebida");
    sys.add_product(std::make_unique<food>(203, "Sushi Combo", 90.0), "Japonesa");

    std::cout << "[ Questao 1 (E) - C++20 Ranges Pipeline ]\n";
    auto caros = sys.get_expensive_product_names(35.0);
    std::cout << "Produtos com preco > R$ 35.0:\n";
    for (const auto& name : caros) {
        std::cout << " - " << name << "\n";
    }
    std::cout << "\n";

    std::cout << "[ Questao 2 (A/D) - Tratamento de Excecoes ]\n";
    try {
        sys.add_product(nullptr, "Invalida");
    } catch (const domain_error& e) {
        std::cout << "Capturado pela BASE (domain_error): " << e.what() << "\n\n";
    }

    std::cout << "[ Questao 2 (B/D) - std::optional ]\n";
    auto achou = sys.find_product_by_id(201);
    if (achou.has_value()) {
        std::cout << "Achou: " << (*achou)->get_name() << "\n";
    }

    auto nao_achou = sys.find_product_by_id(999);
    if (!nao_achou.has_value()) {
        std::cout << "ID 999 nao encontrado (std::nullopt retornado com sucesso).\n\n";
    }

    std::cout << "[ Questao 2 (C/D) - std::variant & std::visit ]\n";
    auto res = sys.process_order_item(201);
    std::visit([](const auto& arg) {
        using T = std::decay_t<decltype(arg)>;
        if constexpr (std::is_same_v<T, food>) {
            std::cout << "Sucesso no Variant: Processado " << arg.get_name() << "\n";
        } else if constexpr (std::is_same_v<T, std::string>) {
            std::cout << "Erro no Variant: " << arg << "\n";
        }
    }, res);
    std::cout << "\n";
    std::cout << "[ Questao 3 (C/D) - Concorrencia Paralela ]\n";
    double total_paralelo = sys.process_prices_in_parallel();
    std::cout << "Soma total processada em paralelo: R$ " << total_paralelo << "\n\n";
    std::cout << "[ Questao 4 (A/B) - Serializacao JSON ]\n";
    sys.save_state();
    std::cout << "Estado do sistema salvo no arquivo 'sistema_estado.json'.\n\n";

    return 0;
}