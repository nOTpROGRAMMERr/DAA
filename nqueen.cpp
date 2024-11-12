#include <stdio.h>
#include <stdbool.h>

#define N 8  // Change this value to solve for a different board size
//O(N!)
// Function to print the board
void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", board[i][j] ? 'Q' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if a queen can be placed at board[row][col]
bool isSafe(int board[N][N], int row, int col) {
    // Check the column
    for (int i = 0; i < row; i++)
        if (board[i][col])
            return false;

    // Check upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check upper right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j])
            return false;

    return true;
}

// Recursive function to solve the N-Queens problem
bool solveNQueens(int board[N][N], int row) {
    // If all queens are placed, return true
    if (row >= N) {
        printBoard(board);  // Print one of the possible solutions
        return true;
    }

    bool solutionFound = false;
    // Try placing queen in each column of the current row
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;  // Place queen

            // Recur to place the queen in the next row
            solutionFound = solveNQueens(board, row + 1) || solutionFound;

            board[row][col] = 0;  // Backtrack
        }
    }

    return solutionFound;
}

// Main function
int main() {
    int board[N][N] = {0};  // Initialize the board with 0s

    if (!solveNQueens(board, 0)) {
        printf("No solution exists for %d-Queens problem.\n", N);
    }

    return 0;
}
