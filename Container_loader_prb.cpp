#include <stdio.h>

void containerLoader(int weights[], int n, int capacity) {
    int currentWeight = 0, i;

    printf("Containers loaded: ");
    for (i = 0; i < n; i++) {
        if (currentWeight + weights[i] <= capacity) {
            currentWeight += weights[i];
            printf("%d ", weights[i]);
        }
    }
    printf("\nTotal weight loaded: %d\n", currentWeight);
}

int main() {
    int n, capacity;

    printf("Enter the number of containers: ");
    scanf("%d", &n);

    int weights[n];
    printf("Enter the weights of the containers: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    printf("Enter the capacity of the loader: ");
    scanf("%d", &capacity);

    containerLoader(weights, n, capacity);

    return 0;
}

