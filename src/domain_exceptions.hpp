#ifndef DOMAIN_EXCEPTIONS_HPP
#define DOMAIN_EXCEPTIONS_HPP

#include <stdexcept>
#include <string>

class domain_error : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

class item_not_found_error : public domain_error {
public:
    explicit item_not_found_error(const std::string& msg)
        : domain_error("Item nao encontrado: " + msg) {}
};

class invalid_item_error : public domain_error {
public:
    explicit invalid_item_error(const std::string& msg)
        : domain_error("Item invalido: " + msg) {}
};

#endif