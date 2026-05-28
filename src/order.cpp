#include "order.hpp"
#include <iostream>

order::order(int id, std::shared_ptr<customer> cust)
    : id_(id), customer_(cust) {
    std::cout << "Pedido (" << id_ << ") criado.\n";
}

order::~order() {
    std::cout << "~Pedido (" << id_ << ") destruido.\n";
}

void order::add_item(std::shared_ptr<product> prod, int quantity) {
    items_.push_back(std::make_unique<order_item>(prod, quantity));
}

double order::calculate_total() const {
    double total = 0.0;
    for (const auto& item : items_) {
        total += item->calculate_subtotal();
    }
    return total;
}