#include <stdbool.h>
#include <stdio.h>

#define V 4

void printSolution(int color[]) {
    printf("Solution: ");
    for (int i = 0; i < V; i++) {
        printf("%d ", color[i]);
    }
    printf("\n");
}

bool isSafe(int graph[V][V], int color[], int v, int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && color[i] == c) return false;
    }
    return true;
}

bool graphColoringUtil(int graph[V][V], int m, int color[], int v) {
    if (v == V) {
        printSolution(color);
        return true;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(graph, color, v, c)) {
            color[v] = c;

            if (graphColoringUtil(graph, m, color, v + 1)) return true;

            color[v] = 0; // Backtrack
        }
    }
    return false;
}

void graphColoring(int graph[V][V], int m) {
    int color[V] = {0};

    if (!graphColoringUtil(graph, m, color, 0)) {
        printf("No solution exists\n");
    }
}

int main() {
    int graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
    };
    int m = 3; // Number of colors

    graphColoring(graph, m);
    return 0;
}

