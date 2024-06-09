#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <typeinfo>

// Function prototypes
void showMenu();
void performAddition();
void performSubtraction();
void performMultiplication();
void performDivision();
bool isValidNumber(const std::string& str);

int main() {
    int choice;
    do {
        showMenu();
        std::cin >> choice;

        // Validate the menu choice input
        while(std::cin.fail() || choice < 1 || choice > 5) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid choice. Please select from the menu (1-5): ";
            std::cin >> choice;
        }

        switch (choice) {
            case 1:
                performAddition();
                break;
            case 2:
                performSubtraction();
                break;
            case 3:
                performMultiplication();
                break;
            case 4:
                performDivision();
                break;
            case 5:
                std::cout << "Exiting the program." << std::endl;
                break;
        }
    } while (choice != 5);

    return 0;
}

void showMenu() {
    std::cout << "\nDigital Calculator\n";
    std::cout << "1. Addition\n";
    std::cout << "2. Subtraction\n";
    std::cout << "3. Multiplication\n";
    std::cout << "4. Division\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
}

void performAddition() {
    std::string input1, input2;
    std::cout << "Enter the first number: ";
    std::cin >> input1;
    std::cout << "Enter the second number: ";
    std::cin >> input2;

    if (isValidNumber(input1) && isValidNumber(input2)) {
        double num1 = std::stod(input1);
        double num2 = std::stod(input2);
        std::cout << "Result: " << num1 << " + " << num2 << " = " << num1 + num2 << std::endl;
    } else {
        std::cout << "Invalid input. Please enter numerical values only." << std::endl;
    }
}

void performSubtraction() {
    std::string input1, input2;
    std::cout << "Enter the first number: ";
    std::cin >> input1;
    std::cout << "Enter the second number: ";
    std::cin >> input2;

    if (isValidNumber(input1) && isValidNumber(input2)) {
        double num1 = std::stod(input1);
        double num2 = std::stod(input2);
        std::cout << "Result: " << num1 << " - " << num2 << " = " << num1 - num2 << std::endl;
    } else {
        std::cout << "Invalid input. Please enter numerical values only." << std::endl;
    }
}

void performMultiplication() {
    std::string input1, input2;
    std::cout << "Enter the first number: ";
    std::cin >> input1;
    std::cout << "Enter the second number: ";
    std::cin >> input2;

    if (isValidNumber(input1) && isValidNumber(input2)) {
        double num1 = std::stod(input1);
        double num2 = std::stod(input2);
        std::cout << "Result: " << num1 << " * " << num2 << " = " << num1 * num2 << std::endl;
    } else {
        std::cout << "Invalid input. Please enter numerical values only." << std::endl;
    }
}

void performDivision() {
    std::string input1, input2;
    std::cout << "Enter the first number: ";
    std::cin >> input1;
    std::cout << "Enter the second number: ";
    std::cin >> input2;

    if (isValidNumber(input1) && isValidNumber(input2)) {
        double num1 = std::stod(input1);
        double num2 = std::stod(input2);
        if (num2 != 0) {
            std::cout << "Result: " << num1 << " / " << num2 << " = " << num1 / num2 << std::endl;
        } else {
            std::cout << "Error: Division by zero is not allowed." << std::endl;
        }
    } else {
        std::cout << "Invalid input. Please enter numerical values only." << std::endl;
    }
}

bool isValidNumber(const std::string& str) {
    std::istringstream iss(str);
    double num;
    iss >> num;
    return !iss.fail() && iss.eof();
}
