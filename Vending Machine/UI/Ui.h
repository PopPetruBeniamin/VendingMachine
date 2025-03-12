//
// Created by Usuario on 20/05/2024.
//

#ifndef LAB_9_10_FINAL_FINAL_UI_H
#define LAB_9_10_FINAL_FINAL_UI_H

#include "../Service/VendingMachine.h"

using namespace std;

class Ui{
private:
    static const int FIRSTCHOICE = 0;
    static const int LASTCHOICE = 4;
    VendingMachine& vendingMachine;
public:
    explicit Ui(VendingMachine& givenVendingMachine);
    ~Ui();

    //============================== Client ==============================
    static void displayMenu();

    static void readingNumbers(DynamicVector<float>& numbers);

    void handlingChoiceClient(int choice);
    void displayProducts();
    void displayCoins();
    void buyProduct();
    void logIn();

    void processingThePurchase(float sum);
    void print_vector(DynamicVector<float>& vector);


    //============================== Admin ==============================
    static void displayMenuAdmin();

    void handlingChoiceAdmin(int choice);

    void runProgram();
    void runProgramAdmin();

    void addProduct();
    void addCoin();
    void removeProduct();
    void removeCoin();
    void updateProduct();
};

#endif //LAB_9_10_FINAL_FINAL_UI_H
