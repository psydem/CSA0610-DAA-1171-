#include <stdio.h>

void findMinMax(int arr[], int n, int *min, int *max, int index) {
    if (index == n) return; // Base case: end of list

    if (arr[index] < *min)
        *min = arr[index];
    if (arr[index] > *max)
        *max = arr[index];

    findMinMax(arr, n, min, max, index + 1); // Recurse for the next element
}

int main() {
    int arr[] = {7, 3, 9, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int min = arr[0], max = arr[0];

    findMinMax(arr, n, &min, &max, 1);
    printf("Minimum value: %d\n", min);
    printf("Maximum value: %d\n", max);
    return 0;
}

