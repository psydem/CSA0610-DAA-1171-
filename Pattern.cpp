#include <stdio.h>

// Function to print numbers in each row
void printRow(int num) {
    if (num == 0) return; // Base case
    printRow(num - 1);    // Recursive call
    printf("%d ", num);
}

// Function to handle spaces and rows
void printPattern(int n, int currentRow) {
    if (currentRow > n) return; // Base case

    // Print leading spaces for alignment
    for (int i = 0; i < n - currentRow; i++) {
        printf(" ");
    }

    // Print numbers in the current row
    printRow(currentRow);
    printf("\n");

    // Recursive call for the next row
    printPattern(n, currentRow + 1);
}

int main() {
    int n;
    printf("Enter the number of rows (n): ");
    scanf("%d", &n);
    printPattern(n, 1);
    return 0;
}

