//
// Created by Usuario on 13/05/2024.
//

#include <cassert>
#include "TestCollection.h"
#include "../Repository/Collection/Collection.h"

void myTestsCollection(){
    Collection<int> c;

    c.add(1);
    c.add(1);
    c.add(1);
    c.add(1);
    c.add(1);

    c.add(2);
    c.add(2);

    c.add(10);
    c.add(10);
    c.add(10);

    //Testing size function
    assert(c.size() == 3);

    //Testing search function
    assert(c.search(1) == true);
    assert(c.search(2) == true);
    assert(c.search(10) == true);
    assert(c.search(20) == false);

    //Testing nroccurrences function
    assert(c.nroccurrences(1) == 5);
    assert(c.nroccurrences(2) == 2);
    assert(c.nroccurrences(10) == 3);
    assert(c.nroccurrences(100) == 0);
    assert(c.nroccurrences(67) == 0);

    //Testing getAt function
    assert(c.getAt(0) == 1);
    assert(c.getAt(1) == 2);
    assert(c.getAt(2) == 10);

    //Testing remove function
    assert(c.remove(2) == true);
    assert(c.remove(2) == true);
    assert(c.search(2) == false);
    assert(c.nroccurrences(2) == 0);
    assert(c.getAt(0) == 1);
    assert(c.getAt(1) == 10);
}
