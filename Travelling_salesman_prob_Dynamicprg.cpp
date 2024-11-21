#include <stdio.h>
#include <limits.h>

#define MAX 4 // Number of cities for this test case

// Recursive function to solve TSP
int tsp(int graph[MAX][MAX], int n, int pos, int visited, int dp[MAX][1 << MAX]) {
    if (visited == (1 << n) - 1) { // All cities visited
        printf("Visiting city 0 from city %d\n", pos); // Returning to starting city
        return graph[pos][0];
    }

    if (dp[pos][visited] != -1) {
        return dp[pos][visited]; // Return already computed value
    }

    int ans = INT_MAX;
    for (int city = 0; city < n; city++) {
        if ((visited & (1 << city)) == 0) { // If the city is not visited
            printf("Visiting city %d from city %d\n", city, pos);
            int newAns = graph[pos][city] + tsp(graph, n, city, visited | (1 << city), dp);
            if (newAns < ans) {
                ans = newAns;
            }
        }
    }

    dp[pos][visited] = ans; // Store the result in the dp table
    return ans;
}

int main() {
    int n = 4; // Number of cities
    int graph[MAX][MAX] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int dp[MAX][1 << MAX]; // Memoization table
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < (1 << MAX); j++) {
            dp[i][j] = -1;
        }
    }

    printf("Calculating Minimum TSP Cost...\n");
    int result = tsp(graph, n, 0, 1, dp); // Start from city 0 with visited bitmask = 1
    printf("Minimum cost of Travelling Salesman Problem: %d\n", result);

    return 0;
}

