#include "order_item.hpp"
#include <iostream>

order_item::order_item(product* prod, int quantity)
    : product_(prod), quantity_(quantity) {
    std::cout << "Item (" << product_->get_name() << ") criado.\n";
}

order_item::~order_item() {
    std::cout << "~Item (" << product_->get_name() << ") destruido.\n";
}

double order_item::calculate_subtotal() const {
    return product_->calculate_price() * quantity_;
}