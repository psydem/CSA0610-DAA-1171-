#include <stdio.h>
#define MAX 10

int board[MAX][MAX];

void printSolution(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c ", board[i][j] ? 'Q' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

int isSafe(int row, int col, int n) {
    for (int i = 0; i < col; i++) // Check left
        if (board[row][i]) return 0;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) // Check upper diagonal
        if (board[i][j]) return 0;
    for (int i = row, j = col; i < n && j >= 0; i++, j--) // Check lower diagonal
        if (board[i][j]) return 0;
    return 1;
}

int solveNQueens(int col, int n) {
    if (col >= n) { // Base case: all queens placed
        printSolution(n);
        return 1;
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        if (isSafe(i, col, n)) {
            board[i][col] = 1; // Place queen
            res = solveNQueens(col + 1, n) || res; // Recur for next column
            board[i][col] = 0; // Backtrack
        }
    }
    return res;
}

int main() {
    int n;
    printf("Enter the value of n for n-Queens: ");
    scanf("%d", &n);
    if (!solveNQueens(0, n)) {
        printf("No solution exists\n");
    }
    return 0;
}

