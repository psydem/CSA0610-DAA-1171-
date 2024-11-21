#include <stdio.h>

typedef struct {
    int weight;
    int value;
    float ratio;
} Item;

void knapsack(Item items[], int n, int capacity) {
    float totalValue = 0.0;
    int i;

    // Sorting items based on value-to-weight ratio in descending order
    for (i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (items[i].ratio < items[j].ratio) {
                Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    printf("Selected items:\n");
    for (i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            // Take the whole item
            capacity -= items[i].weight;
            totalValue += items[i].value;
            printf("Item %d: Weight = %d, Value = %d (100%% taken)\n", i + 1, items[i].weight, items[i].value);
        } else {
            // Take a fraction of the item
            float fraction = (float)capacity / items[i].weight;
            totalValue += items[i].value * fraction;
            printf("Item %d: Weight = %d, Value = %d (%.2f%% taken)\n", i + 1, items[i].weight, items[i].value, fraction * 100);
            capacity = 0;
            break;
        }
    }

    printf("Total value in knapsack: %.2f\n", totalValue);
}

int main() {
    int n, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);
    Item items[n];

    printf("Enter the weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d - Weight: ", i + 1);
        scanf("%d", &items[i].weight);
        printf("Item %d - Value: ", i + 1);
        scanf("%d", &items[i].value);
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    knapsack(items, n, capacity);
    return 0;
}

