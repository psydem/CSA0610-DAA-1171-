#include <stdio.h>

// Recursive function to calculate nCr
int combination(int n, int r) {
    if (r == 0 || r == n) return 1;
    return combination(n - 1, r - 1) + combination(n - 1, r);
}

void printPascal(int n, int i) {
    if (i > n) return; // Base case
    for (int k = 0; k < n - i; k++) printf("  "); // Print spaces
    for (int j = 0; j <= i; j++) printf("%d   ", combination(i, j));
    printf("\n");
    printPascal(n, i + 1);
}

int main() {
    int n;
    printf("Enter the number of rows for Pascal's Triangle: ");
    scanf("%d", &n);
    printPascal(n - 1, 0);
    return 0;
}

