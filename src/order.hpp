#ifndef ORDER_HPP
#define ORDER_HPP
#include "customer.hpp"
#include "order_item.hpp"
#include <vector>

class order {
private:
    int id_;
    customer* customer_; 
    std::vector<order_item*> items_;
public:
    order(int id, customer* cust);
    ~order(); 

    void add_item(product* prod, int quantity);
    double calculate_total() const;
};
#endif