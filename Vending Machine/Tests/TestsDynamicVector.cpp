//
// Created by Usuario on 13/05/2024.
//

#include <cassert>
#include "TestsDynamicVector.h"
#include "../Repository/DynamicVector/DynamicVector.h"

void myTestsDynamicVector(){
    DynamicVector<int> d1, d2(5);

    //d1
    // Testing push_back function
    d1.push_back(3);
    d1.push_back(3);
    d1.push_back(2);
    d1.push_back(1);
    d1.push_back(7);

    assert(d1.getAt(0) == 3);
    assert(d1.getAt(1) == 3);
    assert(d1.getAt(2) == 2);
    assert(d1.getAt(3) == 1);
    assert(d1.getAt(4) == 7);
    assert(d1.size() == 5);

    // Testing pop function
    d1.pop(3);
    assert(d1.getAt(0) == 3);
    assert(d1.getAt(1) == 3);
    assert(d1.getAt(2) == 2);
    assert(d1.getAt(3) == 7);
    assert(d1.size() == 4);

    // Testing pop_back function
    d1.pop_back();
    d1.pop_back();
    assert(d1.getAt(0) == 3);
    assert(d1.getAt(1) == 3);
    assert(d1.size() == 2);

    //Testing [] operator const
    assert(d1[0] == 3);
    assert(d1[1] == 3);

    //Testing [] operator
    d1[0] = 4;
    d1[1] = 101;
    assert(d1[0] == 4);
    assert(d1[1] == 101);

    //d2
    assert(d2.size() == 0);

    d2 = d1;
    assert(d2.size() == 2);
    assert(d2.getAt(0) == 4);
    assert(d2.getAt(1) == 101);
    assert(d2[0] == 4);
    assert(d2[1] == 101);
}
