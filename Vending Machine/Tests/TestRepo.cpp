//
// Created by Usuario on 21/05/2024.
//

#include <cassert>
#include "TestRepo.h"
#include "../Repository/RepoFile.h"
#include "../Domain/Product.h"

void myTestsRepo(){
    RepoFile<float> r(R"(C:\Users\Usuario\CLionProjects\LAB_9_10_FINAL_FINAL\Data\testRepoDataCoins)");

    r.addElement(1);
    r.addElement(1.5);
    r.addElement(2);
    r.addElement(2.5);
    r.addElement(3);
    r.addElement(3.5);

    r.removeElement(2);
    r.removeElement(3);

    r.updateElement(2.5, 25);
    r.updateElement(1.5, 15);
    r.updateElement(3.5, 35);

    RepoFile<Product> r2(R"(C:\Users\Usuario\CLionProjects\LAB_9_10_FINAL_FINAL\Data\testRepoDataProducts)");

    Product p1(1, "CocaCola", 4.55),
            p2(2, "Fanta", 4.35),
            p3(3, "Pepsi", 3.99),
            p4(4, "Capuccino", 6.75),
            p5(5, "Sprite", 5.5);

    r2.addElement(p1);
    r2.addElement(p1);
    r2.addElement(p1);
    r2.addElement(p1);
    r2.addElement(p2);
    r2.addElement(p2);
    r2.addElement(p2);
    r2.addElement(p2);
    r2.addElement(p3);
    r2.addElement(p3);
    r2.addElement(p3);
    r2.addElement(p3);
    r2.addElement(p4);
    r2.addElement(p4);
    r2.addElement(p4);
    r2.addElement(p4);

    //Tengo un problema aqui
    Collection<Product>& c = r2.getElements();
    assert(c[0]==p1);
    assert(c[1]==p2);
    assert(c[2]==p3);
    assert(c[3]==p4);
    assert(c.nroccurrences(p1) == 4);
    assert(c.nroccurrences(p2) == 4);
    assert(c.nroccurrences(p3) == 4);
    assert(c.nroccurrences(p4) == 4);
    assert(c.nroccurrences(p5) == 0);

    r2.removeElement(p1);
    assert(c[0]==p1);
    assert(c[1]==p2);
    assert(c[2]==p3);
    assert(c[3]==p4);
    assert(c.nroccurrences(p1) == 3);
    assert(c.nroccurrences(p2) == 4);
    assert(c.nroccurrences(p3) == 4);
    assert(c.nroccurrences(p4) == 4);
    assert(c.nroccurrences(p5) == 0);

    r2.updateElement(p3, p5);
    assert(c[0]==p1);
    assert(c[1]==p2);
    assert(c[2]==p5);
    assert(c[3]==p4);
    assert(c.nroccurrences(p1) == 3);
    assert(c.nroccurrences(p2) == 4);
    assert(c.nroccurrences(p3) == 0);
    assert(c.nroccurrences(p4) == 4);
    assert(c.nroccurrences(p5) == 4);
}
