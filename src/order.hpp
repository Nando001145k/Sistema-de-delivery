#ifndef ORDER_HPP
#define ORDER_HPP
#include "customer.hpp"
#include "order_item.hpp"
#include <vector>
#include <memory>

class order {
private:
    int id_;
    std::shared_ptr<customer> customer_; // Agregacao
    std::vector<std::unique_ptr<order_item>> items_; // Composicao (dono exclusivo)
public:
    order(int id, std::shared_ptr<customer> cust);
    
    ~order(); 
    
    void add_item(std::shared_ptr<product> prod, int quantity);
    double calculate_total() const;
};
#endif