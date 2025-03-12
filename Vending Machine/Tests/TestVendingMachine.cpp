//
// Created by Usuario on 13/05/2024.
//

#include <cassert>
#include "TestVendingMachine.h"
#include "../Service//VendingMachine.h"

void myTestsVendingMachine(){
    Product p1(1, "Cola", 3.75),
            p2(2, "Fanta", 4.15),
            p3(3, "Sprite", 2.5),
            p4(4, "Pepsi", 4.25),
            p5(5, "Fantasy", 6.75);

    /*VendingMachine v("../Data/TestVendingMachineDataProducts", "../Data/TestVendingMachineDataCoins");

    //=============Testing functions for coin=============
    //Testing add function
    v.addCoin(0.5);
    v.addCoin(0.5);
    v.addCoin(0.5);

    v.addCoin(1);
    v.addCoin(1);
    v.addCoin(1);

    v.addCoin(10);

    //Testing addCoinAndQuantity function
    v.addCoinAndQuantity(20, 5);

    //Testing removeCoin function
    v.removeCoin(0.5);

    //Testing removeAllCoinsByType function
    v.removeAllOccurencesCoin(1);


    //=============Testing functions for product=============
    //Testing add functions
    v.addProduct(p1);
    v.addProduct(p1);
    v.addProduct(p1);
    v.addProduct(p2);
    v.addProduct(p2);
    v.addProduct(p2);
    v.addProduct(p3);
    v.addProduct(p3);
    v.addProduct(p3);

    v.addProductAndQuantity(p4, 3);

    //Testing remove functions
    v.removeProduct(p1);
    v.removeProductByName("Fanta");
    v.removeAllOccurencesProduct(p4);

    //=====================Testing algorithm functions==========================
    //Testing sumElementsVector function
    DynamicVector<float> d1;
    float epsilon = 0.0001;
    d1.push_back(4);
    d1.push_back(2);
    d1.push_back(3);
    d1.push_back(1);

    assert(v.sumElementsVector(d1)==10);

    //Testing transformCollectionToVector function
    DynamicVector<float> d2;
    Collection<float> c2;

    DynamicVector<DynamicVector<float>> allCombinations;
    DynamicVector<float> currentCombination;
    DynamicVector<DynamicVector<float>> filteredCombinationsBySum;

    int counter = 0;

    std::cout << "Hello" << std::endl;
    c2.add(1);
    c2.add(2);
    c2.add(5);

    std::cout << "Hello"  << std::endl;
    v.transformCollectionToVector(c2, d2);
    assert(d2.size() == 3);
    assert(d2[0] == 1);
    assert(d2[1] == 2);
    assert(d2[2] == 5);

    std::cout << "Hello"  << std::endl;
    v.generate_combinations(d2, 0, counter, currentCombination, allCombinations);
    std::cout << "Hello"  << std::endl;
    assert(allCombinations[0].size() == 0);
    assert(allCombinations[1].size() == 1);
    assert(allCombinations[2].size() == 2);
    assert(allCombinations[3].size() == 3);
    assert(allCombinations[4].size() == 2);
    assert(allCombinations[5].size() == 1);
    assert(allCombinations[6].size() == 2);
    assert(allCombinations[7].size() == 1);

    assert(allCombinations[1][0] == 1);

    assert(allCombinations[2][0] == 1);
    assert(allCombinations[2][1] == 2);

    assert(allCombinations[3][0] == 1);
    assert(allCombinations[3][1] == 2);
    assert(allCombinations[3][2] == 5);

    assert(allCombinations[4][0] == 1);
    assert(allCombinations[4][1] == 5);

    assert(allCombinations[5][0] == 2);

    assert(allCombinations[6][0] == 2);
    assert(allCombinations[6][1] == 5);

    assert(allCombinations[7][0] == 5);

    v.filterAllCombinationsBySum(3, filteredCombinationsBySum, allCombinations);

    assert(filteredCombinationsBySum.size() == 1);
    assert(filteredCombinationsBySum[0][0] == 1);
    assert(filteredCombinationsBySum[0][1] == 2);*/
}
