//
// Created by Usuario on 19/05/2024.
//

#ifndef LAB_9_10_FINAL_FINAL_PRODUCT_H
#define LAB_9_10_FINAL_FINAL_PRODUCT_H

#include <string>
#include <iostream>

class Product{
private:
    int code;
    std::string name;
    float price;
public:
    Product();
    Product(int givenCode, std::string givenName, float givenPrice);
    Product(const Product& givenProduct);
    ~Product();

    //Set functions
    void setCode(int givenCode);
    void setName(std::string givenName);
    void setPrice(float givenPrice);

    [[nodiscard]] int getCode() const;
    [[nodiscard]] std::string getName() const;
    [[nodiscard]] float getPrice() const;

    bool operator==(const Product& other);
    bool operator<(const Product& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Product& product);
    friend std::istream& operator>>(std::istream& in, Product& product);
};

#endif //LAB_9_10_FINAL_FINAL_PRODUCT_H
