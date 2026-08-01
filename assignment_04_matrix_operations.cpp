// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_SIZE = 10;

// Function to read a matrix from user input
void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int &rows, int &cols) {
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// Function to display a matrix in a neat grid
void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    cout << "\nMatrix (" << rows << " x " << cols << "):" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(6) << matrix[i][j];
        }
        cout << endl;
    }
}

// PART A: Transpose a matrix
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int matrix_t[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix_t[j][i] = matrix[i][j];
        }
    }
}

// PART B: Add two matrices
void addMatrices(int matA[MAX_SIZE][MAX_SIZE], int matB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matA[i][j] + matB[i][j];
        }
    }
}

// PART C: Multiply two matrices
void multiplyMatrices(int matA[MAX_SIZE][MAX_SIZE], int matB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int colsB) {
    // Initialize result matrix to 0
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
        }
    }
    
    // Perform matrix multiplication
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                result[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int matrix2[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];
    int rows, cols, rows2, cols2;
    int choice;
    
    cout << "=== Matrix Operations ===" << endl;
    cout << "1. Transpose a matrix" << endl;
    cout << "2. Add two matrices" << endl;
    cout << "3. Multiply two matrices" << endl;
    cout << "Choose operation (1-3): ";
    cin >> choice;
    
    if (choice == 1) {
        // PART A: Transpose
        cout << "\n--- Matrix Transpose ---" << endl;
        readMatrix(matrix, rows, cols);
        
        displayMatrix(matrix, rows, cols);
        
        transposeMatrix(matrix, result, rows, cols);
        
        cout << "\nTransposed Matrix (" << cols << " x " << rows << "):" << endl;
        displayMatrix(result, cols, rows);
        
    } else if (choice == 2) {
        // PART B: Addition
        cout << "\n--- Matrix Addition ---" << endl;
        
        cout << "\nEnter Matrix A:" << endl;
        readMatrix(matrix, rows, cols);
        
        cout << "\nEnter Matrix B (same dimensions as Matrix A):" << endl;
        readMatrix(matrix2, rows2, cols2);
        
        if (rows != rows2 || cols != cols2) {
            cout << "Error: Matrices must have the same dimensions!" << endl;
            return 1;
        }
        
        displayMatrix(matrix, rows, cols);
        cout << "\n+\n";
        displayMatrix(matrix2, rows, cols);
        
        addMatrices(matrix, matrix2, result, rows, cols);
        
        cout << "\n=\n";
        displayMatrix(result, rows, cols);
        
    } else if (choice == 3) {
        // PART C: Multiplication
        cout << "\n--- Matrix Multiplication ---" << endl;
        
        cout << "\nEnter Matrix A:" << endl;
        readMatrix(matrix, rows, cols);
        
        cout << "\nEnter Matrix B (rows must equal columns of Matrix A):" << endl;
        readMatrix(matrix2, rows2, cols2);
        
        if (cols != rows2) {
            cout << "Error: Number of columns in A must equal number of rows in B!" << endl;
            return 1;
        }
        
        displayMatrix(matrix, rows, cols);
        cout << "\nx\n";
        displayMatrix(matrix2, rows2, cols2);
        
        multiplyMatrices(matrix, matrix2, result, rows, cols, cols2);
        
        cout << "\n=\n";
        displayMatrix(result, rows, cols2);
        
    } else {
        cout << "Invalid choice!" << endl;
        return 1;
    }
    
    return 0;
}

