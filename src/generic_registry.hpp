#ifndef GENERIC_REGISTRY_HPP
#define GENERIC_REGISTRY_HPP

#include <vector>
#include <concepts>
#include <cstddef>

template <typename T>
concept calculable = requires(const T& t) {
    { t.calculate_price() } -> std::convertible_to<double>;
};

template <calculable T>
class generic_registry {
private:
    std::vector<T> items_;
public:
    void add(T item) {
        items_.push_back(std::move(item));
    }

    const T& at(std::size_t index) const {
        return items_.at(index);
    }

    std::size_t size() const {
        return items_.size();
    }

    const std::vector<T>& items() const {
        return items_;
    }

    double calculate_total_sum() const {
        double total = 0.0;
        for (const auto& item : items_) {
            total += item.calculate_price();
        }
        return total;
    }
};

#endif