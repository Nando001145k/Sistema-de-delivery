#ifndef PRODUCT_HPP
#define PRODUCT_HPP
#include <string>
#include <iostream>

class preparable {
public:
    virtual void prepare() const = 0;
    virtual ~preparable() = default;
};

class product {
protected: 
    int id_;
    std::string name_;
    double price_;
public:
    product(int id, std::string name, double price);
    
    virtual ~product(); 

    std::string get_name() const;
    double get_price() const;   
    void apply_discount(double percentage);
    virtual double calculate_price() const = 0;
    virtual void display() const;
};

class food : public product, public preparable {
public:
    food(int id, std::string name, double price);
    double calculate_price() const override;
    void display() const override; 
    void prepare() const override;

    ~food() override; 
};

class beverage final : public product {
public:
    beverage(int id, std::string name, double price);
    
    double calculate_price() const override;
    void display() const override;

    ~beverage() override;
};

#endif