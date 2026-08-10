#ifndef PRODUCT_HPP
#define PRODUCT_HPP
#include "crtp_counter.hpp"
#include <string>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class preparable {
public:
    virtual void prepare() const = 0;
    virtual ~preparable() = default;
};

class product : public counted<product> {
protected:
    int id_;
    std::string name_;
    double price_;
public:
    product(int id = 0, std::string name = "", double price = 0.0);
    virtual ~product() override = default;

    int get_id() const;
    std::string get_name() const;
    double get_price() const;   
    void apply_discount(double percentage);

    virtual double calculate_price() const = 0;
    virtual void display() const;
    virtual std::string type_name() const = 0;
};

class food : public product, public preparable {
public:
    food(int id = 0, std::string name = "", double price = 0.0);
    double calculate_price() const override;
    void display() const override; 
    void prepare() const override;
    std::string type_name() const override { return "food"; }
};

class beverage final : public product {
public:
    beverage(int id = 0, std::string name = "", double price = 0.0);
    double calculate_price() const override;
    void display() const override;
    std::string type_name() const override { return "beverage"; }
};

void to_json(json& j, const product& p);

#endif