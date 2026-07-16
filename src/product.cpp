#include "product.hpp"

product::product(int id, std::string name, double price)
    : id_(id), name_(name), price_(price) {}

product::~product() {
    std::cout << "[Destrutor Base] product destruido: " << name_ << "\n";
}

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

food::~food() {
    std::cout << "[Destrutor Derivada] food destruido: " << name_ << "\n";
}

double food::calculate_price() const {
    return price_ * 1.10; 
}

void food::display() const {
    product::display();
    std::cout << " (Categoria: Comida)\n";
}

void food::prepare() const {
    std::cout << "Preparando a comida na cozinha: " << name_ << "\n";
}

beverage::beverage(int id, std::string name, double price) : product(id, name, price) {}

beverage::~beverage() {
    std::cout << "[Destrutor Derivada] beverage destruido: " << name_ << "\n";
}

double beverage::calculate_price() const {
    return price_;
}

void beverage::display() const {
    std::cout << "Bebida Gelada [" << id_ << "]: " << name_ << " | Preco final: R$ " << calculate_price() << "\n";
}