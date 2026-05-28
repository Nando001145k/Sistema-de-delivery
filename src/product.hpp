#ifndef PRODUCT_HPP
#define PRODUCT_HPP
#include <string>

class product {
private:
    int id_;
    std::string name_;
    double price_;
public:
    product(int id, std::string name, double price);
    std::string get_name() const;
    double get_price() const;   
    void apply_discount(double percentage);
};
#endif