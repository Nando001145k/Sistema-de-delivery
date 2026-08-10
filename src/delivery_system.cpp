#include "delivery_system.hpp"
#include "domain_exceptions.hpp"
#include <algorithm>
#include <numeric>
#include <ranges>
#include <future>
#include <mutex>
#include <iostream>

delivery_system::delivery_system(repository& repo) : repo_(repo) {}

void delivery_system::add_product(std::unique_ptr<product> prod, const std::string& category) {
    if (!prod) {
        throw invalid_item_error("Ponteiro de produto nulo.");
    }
    registered_categories_.insert(category);
    catalog_map_[prod->get_id()] = std::move(prod);
}

std::optional<const product*> delivery_system::find_product_by_id(int id) const {
    auto it = catalog_map_.find(id);
    if (it != catalog_map_.end()) {
        return it->second.get();
    }
    return std::nullopt;
}

std::vector<std::string> delivery_system::get_expensive_product_names(double price_threshold) const {
    namespace rv = std::ranges::views;

    auto result = catalog_map_ 
        | rv::filter([price_threshold](const auto& pair) {
              return pair.second->calculate_price() > price_threshold;
          })
        | rv::transform([](const auto& pair) {
              return pair.second->get_name();
          });

    std::vector<std::string> names;
    for (const auto& name : result) {
        names.push_back(name);
    }
    return names;
}

double delivery_system::calculate_total_catalog_value() const {
    return std::accumulate(catalog_map_.begin(), catalog_map_.end(), 0.0,
        [](double acc, const auto& pair) {
            return acc + pair.second->calculate_price();
        });
}

std::size_t delivery_system::count_products_above_price(double threshold) const {
    return std::count_if(catalog_map_.begin(), catalog_map_.end(),
        [threshold](const auto& pair) {
            return pair.second->calculate_price() > threshold;
        });
}

double delivery_system::process_prices_in_parallel() const {
    std::mutex mtx;
    double total = 0.0;
    std::vector<std::future<double>> futures;

    for (const auto& [id, prod] : catalog_map_) {
        futures.push_back(std::async(std::launch::async, [&prod = prod]() {
            
            return prod->calculate_price();
        }));
    }

    for (auto& fut : futures) {
        double partial = fut.get(); 
        std::lock_guard<std::mutex> lock(mtx); 
        total += partial;
    }

    return total;
}

operation_result delivery_system::process_order_item(int id) {
    auto opt = find_product_by_id(id);
    if (!opt.has_value()) {
        return std::string("Erro: Produto ID " + std::to_string(id) + " nao existe.");
    }
    return food(id, (*opt)->get_name(), (*opt)->get_price());
}

void delivery_system::save_state() {
    json doc;
    doc["version"] = 1;
    json items_json = json::array();

    for (const auto& [id, prod] : catalog_map_) {
        items_json.push_back(*prod);
    }
    doc["items"] = items_json;
    repo_.save(doc);
}

void delivery_system::load_state() {
    json doc = repo_.load();
    if (doc.contains("items")) {
        
    }
}