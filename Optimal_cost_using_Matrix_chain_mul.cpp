#include <stdio.h>
#include <limits.h>

int matrixChainOrder(int p[], int i, int j) {
    if (i == j) return 0; // Base case: one matrix
    int k, min = INT_MAX, count;

    for (k = i; k < j; k++) {
        count = matrixChainOrder(p, i, k) + matrixChainOrder(p, k + 1, j) +
                p[i - 1] * p[k] * p[j];

        if (count < min)
            min = count;
    }

    return min;
}

int main() {
    int arr[] = {1, 2, 3, 4}; // Example dimensions
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Minimum number of multiplications is %d\n",
           matrixChainOrder(arr, 1, n - 1));
    return 0;
}

