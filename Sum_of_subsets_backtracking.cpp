#include <stdio.h>

void findSubsets(int arr[], int n, int sum, int currentSum, int index, int solution[]) {
    if (currentSum == sum) {
        printf("Subset found: ");
        for (int i = 0; i < index; i++) {
            if (solution[i] == 1) {
                printf("%d ", arr[i]);
            }
        }
        printf("\n");
        return;
    }

    if (index == n || currentSum > sum) return;

    solution[index] = 1; // Include current element
    findSubsets(arr, n, sum, currentSum + arr[index], index + 1, solution);

    solution[index] = 0; // Exclude current element
    findSubsets(arr, n, sum, currentSum, index + 1, solution);
}

int main() {
    int n, sum;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n], solution[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        solution[i] = 0;
    }

    printf("Enter the target sum: ");
    scanf("%d", &sum);

    findSubsets(arr, n, sum, 0, 0, solution);

    return 0;
}

