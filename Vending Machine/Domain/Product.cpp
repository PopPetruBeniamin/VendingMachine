#include "Product.h"
#include <utility>

Product::Product() {
    this->code = 0;
    this->name = "Unknown";
    this->price = 0.0;
}

Product::Product(int givenCode, std::string givenName, float givenPrice) {
    this->code = givenCode;
    this->name = std::move(givenName);
    this->price = givenPrice;
}

Product::Product(const Product &givenProduct) {
    this->code = givenProduct.code;
    this->name = givenProduct.name;
    this->price = givenProduct.price;
}

Product::~Product() = default;

void Product::setCode(int givenCode) {
    this->code = givenCode;
}

void Product::setName(std::string givenName) {
    this->name = std::move(givenName);
}

void Product::setPrice(float givenPrice) {
    this->price = givenPrice;
}

int Product::getCode() const {
    return this->code;
}

std::string Product::getName() const{
    return this->name;
}

float Product::getPrice() const {
    return this->price;
}

bool Product::operator==(const Product &other) {
    return (this->code == other.code && this->name == other.name && this->price == other.price);
}

bool Product::operator<(const Product &other) const {
    return (this->code < other.code);
}

std::ostream &operator<<(std::ostream &os, const Product &product) {
    os << product.code << " " << product.name << " " << product.price;
    return os;
}

std::istream &operator>>(std::istream &in, Product &product) {
    in >> product.code;
    in >> product.name;
    in >> product.price;
    return in;
}
