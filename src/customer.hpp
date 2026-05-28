#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP
#include <string>

class customer {
private:
    std::string name_;
    std::string address_;
public:
    customer(std::string name, std::string address);
    std::string get_name() const;
    std::string get_address() const;
    std::string format_shipping_label() const;
};
#endif