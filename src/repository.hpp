#ifndef REPOSITORY_HPP
#define REPOSITORY_HPP
#include <nlohmann/json.hpp>
#include <string>
#include <fstream>

using json = nlohmann::json;

class repository {
public:
    virtual void save(const json& data) = 0;
    virtual json load() = 0;
    virtual ~repository() = default;
};

class json_repository : public repository {
private:
    std::string filename_;
public:
    explicit json_repository(std::string filename = "delivery_state.json")
        : filename_(std::move(filename)) {}

    void save(const json& data) override {
        std::ofstream file(filename_);
        file << data.dump(2);
    }

    json load() override {
        std::ifstream file(filename_);
        if (!file.is_open()) return json::object();
        json data;
        file >> data;
        return data;
    }
};

class memory_repository : public repository {
private:
    json memory_data_;
public:
    void save(const json& data) override {
        memory_data_ = data;
    }

    json load() override {
        return memory_data_;
    }
};

#endif