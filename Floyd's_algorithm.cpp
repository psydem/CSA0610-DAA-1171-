#include <stdio.h>
#define INF 99999
#define V 4

void floydWarshallRecursive(int dist[V][V], int k, int i, int j) {
    if (k == V) return; // Base case: all intermediate vertices processed

    if (i == V) {
        floydWarshallRecursive(dist, k + 1, 0, 0); // Move to the next intermediate vertex
        return;
    }

    if (j == V) {
        floydWarshallRecursive(dist, k, i + 1, 0); // Move to the next row
        return;
    }

    // Update the shortest path
    if (dist[i][k] + dist[k][j] < dist[i][j]) {
        dist[i][j] = dist[i][k] + dist[k][j];
    }

    floydWarshallRecursive(dist, k, i, j + 1); // Process the next column
}

void printSolution(int dist[V][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[V][V] = {
        {0, 3, INF, 7},
        {8, 0, 2, INF},
        {5, INF, 0, 1},
        {2, INF, INF, 0}
    };

    floydWarshallRecursive(graph, 0, 0, 0);
    printf("The shortest distances between every pair of vertices:\n");
    printSolution(graph);
    return 0;
}

