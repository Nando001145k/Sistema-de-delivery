#ifndef ORDER_ITEM_HPP
#define ORDER_ITEM_HPP
#include "product.hpp"

class order_item {
private:
    product* product_; 
    int quantity_;
public:
    order_item(product* prod, int quantity);  
    ~order_item(); 
    
    double calculate_subtotal() const;
};
#endif