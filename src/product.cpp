#include "product.hpp"

product::product(int id, std::string name, double price)
    : id_(id), name_(name), price_(price) {}

std::string product::get_name() const { return name_; }
double product::get_price() const { return price_; }

// Logica real: recalcula o preco baseado em um desconto
void product::apply_discount(double percentage) {
    if (percentage > 0.0 && percentage <= 100.0) {
        price_ -= price_ * (percentage / 100.0);
    }
}