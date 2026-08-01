// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Function to display the menu
void displayMenu() {
    cout << "\n============================" << endl;
    cout << "     SIMPLE CALCULATOR" << endl;
    cout << "============================" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Modulus" << endl;
    cout << "6. Exponentiation" << endl;
    cout << "7. Quit" << endl;
    cout << "Select an operation (1-7): ";
}

// Function for addition
void addition(double num1, double num2) {
    double result = num1 + num2;
    cout << "Result: " << fixed << setprecision(2) << num1 << " + " << num2 << " = " << result << endl;
}

// Function for subtraction
void subtraction(double num1, double num2) {
    double result = num1 - num2;
    cout << "Result: " << fixed << setprecision(2) << num1 << " - " << num2 << " = " << result << endl;
}

// Function for multiplication
void multiplication(double num1, double num2) {
    double result = num1 * num2;
    cout << "Result: " << fixed << setprecision(2) << num1 << " * " << num2 << " = " << result << endl;
}

// Function for division
void division(double num1, double num2) {
    if (num2 == 0) {
        cout << "Error: Cannot divide by zero." << endl;
    } else {
        double result = num1 / num2;
        cout << "Result: " << fixed << setprecision(2) << num1 << " / " << num2 << " = " << result << endl;
    }
}

// Function for modulus (remainder)
void calculateModulus(int num1, int num2) {
    if (num2 == 0) {
        cout << "Error: Cannot divide by zero." << endl;
    } else {
        int result = num1 % num2;
        cout << "Result: " << num1 << " % " << num2 << " = " << result << endl;
    }
}

// Function for exponentiation
void exponentiation(double base, double exponent) {
    double result = pow(base, exponent);
    cout << "Result: " << fixed << setprecision(2) << base << " ^ " << (int)exponent << " = " << result << endl;
}

int main() {
    int choice;
    double num1, num2;
    bool running = true;
    
    cout << "========== WELCOME ==========" << endl;
    cout << "   Welcome to Calculator!" << endl;
    
    while (running) {
        displayMenu();
        cin >> choice;
        
        // Quit option doesn't require numbers
        if (choice == 7) {
            cout << "Goodbye!" << endl;
            running = false;
            continue;
        }
        
        // For operations 1-6, ask for the two numbers
        if (choice >= 1 && choice <= 6) {
            cout << "Enter first number : ";
            cin >> num1;
            cout << "Enter second number: ";
            cin >> num2;
        }
        
        // Perform the selected operation
        switch (choice) {
            case 1:
                addition(num1, num2);
                break;
            case 2:
                subtraction(num1, num2);
                break;
            case 3:
                multiplication(num1, num2);
                break;
            case 4:
                division(num1, num2);
                break;
            case 5:
                calculateModulus((int)num1, (int)num2);
                break;
            case 6:
                exponentiation(num1, num2);
                break;
            case 7:
                // Already handled above
                break;
            default:
                cout << "Error: Invalid choice. Please select 1-7." << endl;
        }
    }
    
    return 0;
}

