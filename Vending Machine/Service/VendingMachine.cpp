//
// Created by Usuario on 20/05/2024.
//
#include "VendingMachine.h"

VendingMachine::VendingMachine(RepoFile<Product> &givenRepoProducts, RepoFile<float> &givenRepCoins) : products(givenRepoProducts), coins(givenRepCoins) {}

void VendingMachine::addProduct(const Product &givenProduct) {
    products.addElement(givenProduct);
}

void VendingMachine::addProductAndQuantity(const Product &givenProduct, int givenQuantity) {
    for(int i = 0; i < givenQuantity; i++)
        products.addElement(givenProduct);
}

void VendingMachine::addCoin(float givenCoin) {
    coins.addElement(givenCoin);
}

void VendingMachine::addCoinAndQuantity(float givenCoin, int givenQuantity) {
    for(int i = 0; i < givenQuantity; i++)
        coins.addElement(givenCoin);
}

void VendingMachine::removeProduct(const Product &givenProduct) {
    products.removeElement(givenProduct);
}

void VendingMachine::removeAllOccurencesProduct(const Product &givenProduct) {
    Collection<Product>& c = products.getElements();

    int quantity = c.nroccurrences(givenProduct);
    for(int i = 0; i < quantity; i++)
        products.removeElement(givenProduct);
}

void VendingMachine::removeCoin(float givenCoin) {
    coins.removeElement(givenCoin);
}

void VendingMachine::removeAllOccurencesCoin(float givenCoin) {
    Collection<float>& c = coins.getElements();

    int quantity = c.nroccurrences(givenCoin);
    for(int i = 0; i < quantity; i++)
        coins.removeElement(givenCoin);
}

void VendingMachine::removeProductByName(const std::string &givenNameProduct) {
    Collection<Product>& c = products.getElements();

    for(int i = 0; i < c.size(); i++)
        if(c[i].getName() == givenNameProduct)
            products.removeElement(c[i]);
}

void VendingMachine::updateProduct(const Product &searchedProduct, const Product &givenProduct) {
    products.updateElement(searchedProduct, givenProduct);
}

Collection<Product>& VendingMachine::getRepoProducts() {
    return products.getElements();
}

Collection<float>& VendingMachine::getRepoCoins() {
    return coins.getElements();
}

float VendingMachine::getPriceProductByName(const std::string &givenNameProduct) {
    Collection<Product>& c = products.getElements();
    for(int i = 0; i < c.size(); i++)
        if(c[i].getName() == givenNameProduct)
            return c[i].getPrice();
    return 0.0;
}

bool VendingMachine::searchProductByName(const std::string &givenNameProduct) {
    Collection<Product>& c = products.getElements();
    for(int i = 0; i < c.size(); i++)
        if(c[i].getName() == givenNameProduct)
            return true;
    return false;
}

//=============================================== Logical operations ===============================================

float VendingMachine::sumElementsVector(DynamicVector<float> &givenVector) {
    float sum = 0.0;
    for(int i = 0; i < givenVector.size(); i++)
        sum = sum + givenVector[i];
    return sum;
}


