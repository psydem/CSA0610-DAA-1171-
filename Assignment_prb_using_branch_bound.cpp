#include <stdio.h>
#include <limits.h>

#define N 4

int findMinCost(int cost[N][N], int assignment[N]) {
    int minCost = 0;
    for (int i = 0; i < N; i++) {
        minCost += cost[i][assignment[i]];
    }
    return minCost;
}

void assignTasks(int cost[N][N]) {
    int assignment[N] = {0, 1, 2, 3};
    int minCost = findMinCost(cost, assignment);

    printf("Minimum assignment cost: %d\n", minCost);
}

int main() {
    int cost[N][N] = {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4},
    };

    assignTasks(cost);

    return 0;
}

