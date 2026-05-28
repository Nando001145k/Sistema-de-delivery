#include "customer.hpp"

customer::customer(std::string name, std::string address)
    : name_(name), address_(address) {}

std::string customer::get_name() const { return name_; }
std::string customer::get_address() const { return address_; }
std::string customer::format_shipping_label() const {
    return "Destinatario: " + name_ + "\nEndereco: " + address_;
}