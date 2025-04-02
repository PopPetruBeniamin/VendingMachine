# 🏪 VendingMachine Application

## 📖 Description
The VendingMachine application is a stratified and modular program that simulates the operation of a vending machine. It is designed using Object-Oriented Programming (OOP) principles and incorporates efficient data structures to manage products, users, and transactions effectively.

---

## ✨ Key Features
### 🔹 **1. Object-Oriented Programming (OOP)**
- **Encapsulation**: The application organizes its components into well-defined classes with private attributes and public methods.
- **Operator Overloading**: Several operators (`<<`, `>>`, `==`, `<`) are overloaded to facilitate intuitive manipulation of `Product` objects.
- **Constructors and Destructors**: Multiple constructors are provided for different initialization scenarios, along with a destructor to properly free resources.

### 🔹 **2. Efficient Data Structure Utilization**
-  **Collections and Dynamic Vectors**: Used for efficient storage and manipulation of products, users, and transactions.
-  **Dynamic Memory Management**: Ensures optimal performance when handling product lists and transaction history.

### 🔹 **3. User Roles: Client & Administrator**
The application provides two distinct user roles:
- Can browse products, add items to the cart, and make purchases.  
- Can add, update, or remove products and manage stock levels.

### 🔹 **4. Comprehensive Unit Testing**
The application includes unit tests to validate the correctness of critical functionalities:
- ✅ Product and user data integrity
- ✅ Correct functionality of collection-based storage
- ✅ Robustness of service-layer operations

---

## 🏗️ Code Structure
The program is structured into:
- 📂 **Data/**: Contains the data files.
- 📂 **Domain/**: Defines the `Product` class with its attributes and methods.
- 📂 **Repository/**: Handles data storage and retrieval.
- 📂 **Service/**: Implements the logic for vending machine operations.
- 📂 **UI/**: Provides the command-line interface for user interaction.
- 📂 **Tests/**: Contains unit tests to ensure the reliability of the application.
- 📂 **main.cpp**: The entry point of the application, integrating all components.

---

## 🏆 Conclusion
The VendingMachine application demonstrates the power of Object-Oriented Programming (OOP), modular architecture, and efficient data structures in a real-world scenario. With its user role differentiation, layered structure, and comprehensive testing, it offers a robust vending machine simulation. 🚀 
