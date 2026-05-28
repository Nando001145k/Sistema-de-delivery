#include "customer.hpp"
#include "product.hpp"
#include "order.hpp"
#include <iostream>
#include <memory>

int main() {
    std::cout << "--- Lancheira Voadora ---\n\n";

    // Instanciando os objetos (Demonstrando as logicas de Customer e Product)
    auto cli = std::make_shared<customer>("Luis Fernando", "Rua do Caju, N 15");
    auto prod = std::make_shared<product>(101, "Cachorro-Quente Classico", 12.50);

    std::cout << "[ Testando logica do Cliente ]\n";
    std::cout << cli->format_shipping_label() << "\n\n";

    std::cout << "[ Testando logica do Produto ]\n";
    std::cout << "Preco normal: R$ " << prod->get_price() << "\n";
    prod->apply_discount(10.0); // 10% de desconto
    std::cout << "Preco com desconto (10%): R$ " << prod->get_price() << "\n\n";

    // Bloco para demonstrar os destrutores (Ciclo de Vida / Composicao)
    {
        std::cout << "[ Iniciando Pedido ]\n";
        order pedido(1, cli);
        
        pedido.add_item(prod, 2); // Logica real do Pedido
        
        std::cout << "Total do pedido: R$ " << pedido.calculate_total() << "\n";
        
        std::cout << "\n[ Fim do bloco - Destruindo o pedido ]\n";
    } // O pedido sai de escopo e eh destruido junto com os itens (Composicao)

    std::cout << "\n[ Fora do bloco ]\n";
    std::cout << "Cliente " << cli->get_name() << " e Produto " << prod->get_name() 
              << " continuam existindo (Agregacao).\n";

    return 0;
}