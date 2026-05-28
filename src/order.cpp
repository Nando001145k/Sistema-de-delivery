#include "order.hpp"
#include <iostream>

order::order(int id, customer* cust)
    : id_(id), customer_(cust) {
    std::cout << "Pedido (" << id_ << ") criado.\n";
}

order::~order() {
    for (auto item : items_) {
        delete item; 
    }
    std::cout << "~Pedido (" << id_ << ") destruido.\n";
}

void order::add_item(product* prod, int quantity) {
    items_.push_back(new order_item(prod, quantity));
}

double order::calculate_total() const {
    double total = 0.0;
    for (const auto& item : items_) {
        total += item->calculate_subtotal();
    }
    return total;
}