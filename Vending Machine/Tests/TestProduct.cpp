//
// Created by Usuario on 04/05/2024.
//

#include "TestProduct.h"

void myTestsProducts(){
    float e = 0.001;
    Product p1, p2(1, "ColaCao", 3.76);

    assert(p1.getCode() == 0);
    assert(p1.getName() == "Unknown");
    assert(p1.getPrice() == 0.0);
    assert(p2.getCode() == 1);
    assert(p2.getName() == "ColaCao");
    assert(p2.getPrice() - 3.76 < e);

    p1.setCode(2);
    p1.setName("Fanta");
    p1.setPrice(5.75);

    assert(p1.getCode() == 2);
    assert(p1.getName() == "Fanta");
    assert(p1.getPrice() - 5.75 < e);

    assert((p1 == p2 ) == 0);
}