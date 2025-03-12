cmake_minimum_required(VERSION 3.27)
project(LAB_9_10_FINAL_FINAL)

set(CMAKE_CXX_STANDARD 17)

add_executable(LAB_9_10_FINAL_FINAL main.cpp
        Domain/Product.h
        Domain/Product.cpp
        Repository/Collection/Collection.h
        Repository/DynamicVector/DynamicVector.h
        Repository/Repo.h
        Repository/RepoFile.h
        Service/VendingMachine.cpp
        Service/VendingMachine.h
        UI/Ui.cpp
        UI/Ui.h
        Tests/TestCollection.cpp
        Tests/TestProduct.cpp
        Tests/TestProduct.h
        Tests/TestsDynamicVector.cpp
        Tests/TestsDynamicVector.h
        Tests/TestVendingMachine.cpp
        Tests/TestVendingMachine.h
        Tests/TestRepo.cpp
        Tests/TestRepo.h
)
