#include "customer.hpp"
#include "product.hpp"
#include "order.hpp"
#include <iostream>
#include <vector>
#include <memory>

const product* maior_valor(const std::vector<std::unique_ptr<product>>& itens) {
    if (itens.empty()) return nullptr;
    
    const product* maior = itens[0].get();
    for (const auto& item : itens) {
        if (item->calculate_price() > maior->calculate_price()) {
            maior = item.get();
        }
    }
    return maior;
}

void enviar_para_cozinha(const preparable& item_preparavel) {
    std::cout << "--> Despacho via Interface: ";
    item_preparavel.prepare(); 
}

int main() {
    std::cout << "--- SISTEMA DELIVERY (TP2) ---\n\n";
    std::vector<std::unique_ptr<product>> itens_polimorficos;
    itens_polimorficos.push_back(std::make_unique<food>(201, "Hamburguer Artesanal", 30.0));
    itens_polimorficos.push_back(std::make_unique<beverage>(202, "Refrigerante Lata", 8.0));
    itens_polimorficos.push_back(std::make_unique<food>(203, "Pizza Calabresa", 45.0));

    std::cout << "[ Questao 2 (B) - Despacho Virtual ]\n";
    
    for (const auto& item : itens_polimorficos) {
        item->display();
        std::cout << "Preco calculado: R$ " << item->calculate_price() << "\n\n";
    }

    std::cout << "[ Questao 2 (D) - Funcao Livre / Maior Valor ]\n";
    const product* mais_caro = maior_valor(itens_polimorficos);
    if (mais_caro) {
        std::cout << "O item mais caro custa: R$ " << mais_caro->calculate_price() << " (" << mais_caro->get_name() << ")\n\n";
    }

    std::cout << "[ Questao 3 (D) - Uso de Interface Pura por referencia ]\n";
    food porcao_fritas(204, "Batata Frita", 20.0);
    enviar_para_cozinha(porcao_fritas);
    std::cout << "\n";

    std::cout << "[ Questao 1 (C) e 2 (C) - Destruidores Virtuais e Vazamentos ]\n";
    std::cout << "Limpando o vetor explicitamente para ver a ordem de destruicao:\n";
    itens_polimorficos.clear(); 
    std::cout << "Fim da limpeza do vetor.\n\n";

    return 0;
}