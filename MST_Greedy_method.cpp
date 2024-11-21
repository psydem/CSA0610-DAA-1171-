#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, weight;
} Edge;

typedef struct {
    int parent;
    int rank;
} Subset;

int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void unionSet(Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

int compareEdges(const void *a, const void *b) {
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

void kruskal(Edge edges[], int n, int e) {
    qsort(edges, e, sizeof(Edge), compareEdges);

    Subset subsets[n];
    for (int i = 0; i < n; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    Edge result[n - 1];
    int resultIndex = 0, edgeIndex = 0;

    while (resultIndex < n - 1 && edgeIndex < e) {
        Edge nextEdge = edges[edgeIndex++];
        int x = find(subsets, nextEdge.u);
        int y = find(subsets, nextEdge.v);

        if (x != y) {
            result[resultIndex++] = nextEdge;
            unionSet(subsets, x, y);
        }
    }

    printf("Edges in the MST:\n");
    for (int i = 0; i < resultIndex; i++)
        printf("%d -- %d == %d\n", result[i].u, result[i].v, result[i].weight);
}

int main() {
    int n, e;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &n, &e);

    Edge edges[e];
    printf("Enter the edges (u, v, weight):\n");
    for (int i = 0; i < e; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);

    kruskal(edges, n, e);
    return 0;
}

