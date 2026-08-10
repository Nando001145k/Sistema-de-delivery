#ifndef DELIVERY_SYSTEM_HPP
#define DELIVERY_SYSTEM_HPP
#include "product.hpp"
#include "repository.hpp"
#include <vector>
#include <map>
#include <unordered_set>
#include <optional>
#include <variant>
#include <memory>

using operation_result = std::variant<food, std::string>;

class delivery_system {
private:
    repository& repo_; 
    std::map<int, std::unique_ptr<product>> catalog_map_; 
    std::unordered_set<std::string> registered_categories_; 

public:
    explicit delivery_system(repository& repo);

    void add_product(std::unique_ptr<product> prod, const std::string& category);

    std::optional<const product*> find_product_by_id(int id) const;
    std::vector<std::string> get_expensive_product_names(double price_threshold) const;

    double calculate_total_catalog_value() const;
    std::size_t count_products_above_price(double threshold) const;

    double process_prices_in_parallel() const;

    operation_result process_order_item(int id);

    void save_state();
    void load_state();
};

#endif