#include <iostream>
#include "Repository/RepoFile.h"
#include "Domain/Product.h"
#include "Service/VendingMachine.h"
#include "UI/Ui.h"
#include "Tests/TestProduct.h"
#include "Tests/TestCollection.h"
#include "Tests/TestsDynamicVector.h"
#include "Tests/TestVendingMachine.h"
#include "Tests/TestRepo.h"

int main() {
    //myTestsProducts();
    //myTestsDynamicVector();
    //myTestsCollection();
    //myTestsRepo();
    //myTestsVendingMachine();

    RepoFile<Product> repositoryProducts("Data/dataProducts");
    RepoFile<float> repositoryCoins("Data/dataProducts");

    VendingMachine v(repositoryProducts, repositoryCoins);
    Ui ui(v);
    ui.runProgram();
    return 0;
}
