// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
//
// TASK: Fibonacci Sequence Generator
//
// The Fibonacci sequence is a series of numbers where each number is the sum
// of the two numbers before it:
//
//   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
//
// Write a C++ program with TWO parts, each implemented as a function.
//
// -----------------------------------------------------------------------------
// PART A — Print the First N Terms
// -----------------------------------------------------------------------------
// - Ask the user how many terms (N) to display.
// - Print the first N numbers of the Fibonacci sequence on one line.
//
// Example:
//   How many terms? 7
//   Fibonacci sequence: 0 1 1 2 3 5 8
//
// -----------------------------------------------------------------------------
// PART B — Check if a Number Belongs to the Sequence
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Determine whether that number is a Fibonacci number.
// - Print an appropriate message.
//
// Example:
//   Enter a number to check: 13
//   13 is a Fibonacci number.
//
//   Enter a number to check: 20
//   20 is NOT a Fibonacci number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use a loop (not recursion) to generate the sequence in both parts.
// - N must be a positive integer. If it is not, print an error message.
// - Each part must be implemented in its own function (see scaffold below).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

// PART A: Print the first N terms of Fibonacci sequence
void printFibonacci(int n) {
    // Validate input
    if (n <= 0) {
        cout << "Error: Number of terms must be positive." << endl;
        return;
    }
    
    cout << "Fibonacci sequence: ";
    
    // Handle first term
    if (n >= 1) {
        cout << 0;
    }
    
    // Handle second term
    if (n >= 2) {
        cout << " 1";
    }
    
    // Generate remaining terms
    if (n > 2) {
        long long prev2 = 0;  // First Fibonacci number
        long long prev1 = 1;  // Second Fibonacci number
        long long current;
        
        for (int i = 3; i <= n; i++) {
            current = prev1 + prev2;
            cout << " " << current;
            prev2 = prev1;
            prev1 = current;
        }
    }
    
    cout << endl;
}

// PART B: Check if a number is in the Fibonacci sequence
void checkFibonacci(long long num) {
    // Generate Fibonacci numbers until we exceed the target
    long long prev2 = 0;
    long long prev1 = 1;
    
    // Check if num is 0 or 1 (first two Fibonacci numbers)
    if (num == 0 || num == 1) {
        cout << num << " is a Fibonacci number." << endl;
        return;
    }
    
    // Generate subsequent Fibonacci numbers
    long long current = prev1 + prev2;
    while (current <= num) {
        if (current == num) {
            cout << num << " is a Fibonacci number." << endl;
            return;
        }
        prev2 = prev1;
        prev1 = current;
        current = prev1 + prev2;
    }
    
    // If we reach here, num is not a Fibonacci number
    cout << num << " is NOT a Fibonacci number." << endl;
}

int main() {
    int choice;
    
    cout << "=== Fibonacci Sequence Program ===" << endl;
    cout << "1. Print first N terms" << endl;
    cout << "2. Check if a number is Fibonacci" << endl;
    cout << "Choose option (1 or 2): ";
    cin >> choice;
    
    if (choice == 1) {
        // PART A
        int n;
        cout << "How many terms? ";
        cin >> n;
        printFibonacci(n);
        
    } else if (choice == 2) {
        // PART B
        long long num;
        cout << "Enter a number to check: ";
        cin >> num;
        checkFibonacci(num);
        
    } else {
        cout << "Invalid choice!" << endl;
    }
    
    return 0;
}

