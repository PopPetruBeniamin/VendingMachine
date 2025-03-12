//
// Created by Usuario on 20/05/2024.
//

#ifndef LAB_9_10_FINAL_FINAL_VENDINGMACHINE_H
#define LAB_9_10_FINAL_FINAL_VENDINGMACHINE_H

#include <string>
#include "../Domain/Product.h"
#include "../Repository/RepoFile.h"

class VendingMachine{
private:
    RepoFile<Product>& products;
    RepoFile<float>& coins;
public:
    VendingMachine(RepoFile<Product>& givenRepoProducts, RepoFile<float>& givenRepCoins);
    ~VendingMachine() = default;

    //Add functions
    void addProduct(const Product& givenProduct);
    void addProductAndQuantity(const Product& givenProduct, int givenQuantity);
    void addCoin(float givenCoin);
    void addCoinAndQuantity(float givenCoin, int givenQuantity);

    //Remove functions
    void removeProduct(const Product& givenProduct);
    void removeAllOccurencesProduct(const Product& givenProduct);
    void removeProductByName(const std::string& givenNameProduct);
    void removeCoin(float givenCoin);
    void removeAllOccurencesCoin(float givenCoin);

    //Update functions
    void updateProduct(const Product& searchedProduct, const Product& givenProduct);

    //Get functions
    Collection<Product>& getRepoProducts();
    Collection<float>& getRepoCoins();
    float getPriceProductByName(const std::string& givenNameProduct);

    //Search functions
    bool searchProductByName(const std::string& givenNameProduct);
    float sumElementsVector(DynamicVector<float> &givenVector);

    //Logical operations to determine all combinations of the rest

    // 20 10 5 1 0.5
    // 4  3  5 7 9

    //98 = 4*20 + 1*10 + 1*5 + 3*1
    // Collection --> 20: 4, 10: 1, 5: 1, 1: 3
    // remove --> for(int i = 0; i < c.size(); i++);
};
#endif //LAB_9_10_FINAL_FINAL_VENDINGMACHINE_H
