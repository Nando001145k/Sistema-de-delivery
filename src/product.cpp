#include "product.hpp"

product::product(int id, std::string name, double price)
    : id_(id), name_(name), price_(price) {}

int product::get_id() const { return id_; }
std::string product::get_name() const { return name_; }
double product::get_price() const { return price_; }

void product::apply_discount(double percentage) {
    if (percentage > 0.0 && percentage <= 100.0) {
        price_ -= price_ * (percentage / 100.0);
    }
}

void product::display() const {
    std::cout << "Produto [" << id_ << "]: " << name_ << " | Preco base: R$ " << price_;
}

food::food(int id, std::string name, double price) : product(id, name, price) {}

double food::calculate_price() const { return price_ * 1.10; }

void food::display() const {
    product::display();
    std::cout << " (Categoria: Comida)\n";
}

void food::prepare() const {
    std::cout << "Preparando comida: " << name_ << "\n";
}

beverage::beverage(int id, std::string name, double price) : product(id, name, price) {}

double beverage::calculate_price() const { return price_; }

void beverage::display() const {
    std::cout << "Bebida Gelada [" << id_ << "]: " << name_ << " | Preco: R$ " << calculate_price() << "\n";
}

void to_json(json& j, const product& p) {
    j = json{
        {"type", p.type_name()},
        {"id", p.get_id()},
        {"name", p.get_name()},
        {"price", p.get_price()}
    };
}