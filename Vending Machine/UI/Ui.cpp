//
#include <iostream>
#include <cmath>
#include <sstream>
#include <limits>
#include <algorithm>
#include "../UI/Ui.h"

//
// Created by Usuario on 20/05/2024.
Ui::Ui(VendingMachine &givenVendingMachine) : vendingMachine(givenVendingMachine) {}

Ui::~Ui() = default;

void Ui::displayMenu() {
    cout << "================= Welcome - Client Menu =================\n";
    cout << "1. Display products\n";
    cout << "2. Display coins\n";
    cout << "3. Buy product\n";
    cout << "4. Log in\n";
    cout << "0. Exit\n";
    cout << "Type your option:";
}

void Ui::handlingChoiceClient(int choice) {
    switch(choice){
        case 0:
            break;
        case 1:
            displayProducts();
            break;
        case 2:
            displayCoins();
            break;
        case 3:
            buyProduct();
            break;
        case 4:
            logIn();
            break;
        default:
            cout << "Invalid choice. Try Please enter a number between " << FIRSTCHOICE << " and " << LASTCHOICE << ":";
            break;
    }
}

void Ui::displayProducts() {
    Collection<Product>& c = this->vendingMachine.getRepoProducts();
    Product currentProduct;

    if(c.size() > 0){
        for(int i = 0; i < c.size(); i++){
            currentProduct = c.getAt(i);
            cout << "Product <" << "Code: " << currentProduct.getCode() << ";" << " Name: " << currentProduct.getName() << ";" << " Price: " << currentProduct.getPrice() << ">" << " * " << c.nroccurrences(currentProduct) << " units" << endl;
        }
    }
    else
        cout << "There are no products!\n";
}

void Ui::displayCoins() {
    Collection<float>& c = this->vendingMachine.getRepoCoins();
    float currentCoin;

    if(c.size() > 0){
        for(int i = 0; i < c.size(); i++){
            currentCoin = c.getAt(i);
            cout << "Coin: " << currentCoin << "$" << " x " << c.nroccurrences(currentCoin) << endl;
        }
    }
    else
        cout << "There are no coins!\n";
}

void Ui::logIn() {
    string password;

    cout << "Introduce the password:";
    cin >> password;

    if(password != "1234")
        cout << "Incorrect password!!\n";
    else
        runProgramAdmin();
}

void Ui::readingNumbers(DynamicVector<float>& numbers) {
    string linea;

    cout << "Please, introduce a line of floating";
    cout << " numbers separated by spaces:\n";
    getline(std::cin, linea);

    istringstream iss(linea);
    float num;
    while (iss >> num) {
        numbers.push_back(num);
    }
    cout << endl;
}

void Ui::buyProduct() {
    DynamicVector<float> numbers;
    Product productSearchedFor;
    string nameProduct;
    float sum;
    float rest;

    cout << "What product do you want to buy? (Please introduce the name of a product):";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, nameProduct);

    if(this->vendingMachine.searchProductByName(nameProduct)){
        readingNumbers(numbers);
        sum = this->vendingMachine.sumElementsVector(numbers);

        if(sum >= this->vendingMachine.getPriceProductByName(nameProduct)){
            for(int i = 0 ; i < numbers.size() ; i++)
                this->vendingMachine.addCoin(numbers[i]);
            this->vendingMachine.removeProductByName(nameProduct);
            rest = sum - this->vendingMachine.getPriceProductByName(nameProduct);
            processingThePurchase(rest);
        }
        else{
            cout << "It's not enough money!!\n";
        }
    }
    else{
        cout << "The product don't exist!\n";
    }
}

void Ui::processingThePurchase(float sum) {
    Collection<float>& c = this->vendingMachine.getRepoCoins();
    Collection<float> rest;
    float sumHowMany;
    float currentCoin;
    int howMany;
    int occurrences;
    int division;

    for(int i = 0; i < c.size(); i++){
        sumHowMany = 0.0;
        currentCoin = c.getAt(i);
        division = sum/currentCoin;
        occurrences = c.nroccurrences(currentCoin);

        howMany = min(division,occurrences);

        for(int  j = 0; j < howMany; j++){
            rest.add(currentCoin);
            sumHowMany += currentCoin;
        }
        sum -= sumHowMany;
        if(sum == 0.0)
            break;
    }
    if(sum > 0)
        cout << "I'm sorry. I can't give the rest. I haven't sufficient money!\n";
    else{
        cout << "The rest:\n";
        for(int i = 0; i < rest.size(); i++){
            currentCoin = rest.getAt(i);
            cout  << currentCoin << "$ * " << rest.nroccurrences(currentCoin) << endl;
        }
        for(int i = 0; i < rest.size(); i++){
            currentCoin = rest.getAt(i);
            for(int j = 0; j < rest.nroccurrences(currentCoin); i++)
                this->vendingMachine.removeCoin(currentCoin);
        }
    }
}

void Ui::print_vector(DynamicVector<float>& vector) {
    for (int i = 0; i < vector.size(); ++i) {
        std::cout << vector[i] << "$ ";
    }
    cout << endl;
}

void Ui::runProgram() {
    int choice;
    do{
        displayMenu();
        cin >> choice;
        handlingChoiceClient(choice);
    }while(choice);
}

//=================================================== Admin ===================================================

void Ui::displayMenuAdmin() {
    cout << "================= Welcome - ADMIN =================\n";
    cout << "1. Display products\n";
    cout << "2. Display coins\n";
    cout << "3. Add product\n";
    cout << "4. Add coin\n";
    cout << "5. Remove product\n";
    cout << "6. Remove coin\n";
    cout << "7. Update product\n";
    cout << "0. Log out\n";
}

void Ui::handlingChoiceAdmin(int choice) {
    switch(choice){
        case 0:
            break;
        case 1:
            displayProducts();
            break;
        case 2:
            displayCoins();
            break;
        case 3:
            addProduct();
            break;
        case 4:
            addCoin();
            break;
        case 5:
            removeProduct();
            break;
        case 6:
            removeCoin();
            break;
        case 7:
            updateProduct();
            break;
        default:
            cout << "Invalid choice. Try Please enter a number between " << FIRSTCHOICE << " and " << LASTCHOICE << ":";
            break;
    }
}

void Ui::addProduct() {
    int givenCode;
    string givenName;
    float givenPrice;
    int quantity;

    cout << "Type the code of the product:";
    cin >> givenCode;
    cout << "Type the name of the product:";
    cin >> givenName;
    cout << "Type the price of the product:";
    cin >> givenPrice;

    cout << "How many of this product do you want to add?";
    cin >> quantity;

    Product p(givenCode, givenName, givenPrice);
    this->vendingMachine.addProductAndQuantity(p, quantity);
}

void Ui::addCoin() {
    float givenCoin;
    int quantity;

    cout << "Type the value of the coin that you want to add:";
    cin >> givenCoin;

    cout << "How many of this coin do you want to add?";
    cin >> quantity;

    this->vendingMachine.addCoinAndQuantity(givenCoin, quantity);
}

void Ui::removeProduct() {
    int givenCode;
    string givenName;
    float givenPrice;

    cout << "Type the code of the product that you want to remove:";
    cin >> givenCode;
    cout << "Type the name of the product that you want to remove:";
    cin >> givenName;
    cout << "Type the price of the product that you want to remove:";
    cin >> givenPrice;

    Product p(givenCode, givenName, givenPrice);
    this->vendingMachine.removeAllOccurencesProduct(p);
}

void Ui::removeCoin() {
    float givenCoin;

    cout << "Type the coin that you want to remove:";
    cin >> givenCoin;

    this->vendingMachine.removeAllOccurencesCoin(givenCoin);
}

void Ui::updateProduct() {
    int givenCode;
    string givenName;
    float givenPrice;

    cout << "Type the code of the searched product:";
    cin >> givenCode;
    cout << "Type the name of the searched product:";
    cin >> givenName;
    cout << "Type the price of the searched product:";
    cin >> givenPrice;

    Product searchedProduct(givenCode, givenName, givenPrice);

    cout << "Type the code of the new product:";
    cin >> givenCode;
    cout << "Type the name of the new product:";
    cin >> givenName;
    cout << "Type the price of the new product:";
    cin >> givenPrice;

    Product newProduct(givenCode, givenName, givenPrice);
    this->vendingMachine.updateProduct(searchedProduct, newProduct);
}

void Ui::runProgramAdmin() {
    int choice;
    do{
        displayMenuAdmin();
        cin >> choice;
        handlingChoiceAdmin(choice);
    }while(choice);
}
