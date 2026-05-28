#ifndef ORDER_ITEM_HPP
#define ORDER_ITEM_HPP
#include "product.hpp"
#include <memory>

class order_item {
private:
    std::shared_ptr<product> product_; // Agregacao (usa shared_ptr)
    int quantity_;
public:
    order_item(std::shared_ptr<product> prod, int quantity);

    ~order_item(); 

    double calculate_subtotal() const;
};
#endif