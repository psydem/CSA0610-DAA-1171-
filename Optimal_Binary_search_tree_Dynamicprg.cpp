#include <stdio.h>
#include <limits.h>

void optimalBST(int keys[], int freq[], int n) {
    int cost[n][n];
    
    for (int i = 0; i < n; i++)
        cost[i][i] = freq[i];

    for (int l = 2; l <= n; l++) {
        for (int i = 0; i <= n - l; i++) {
            int j = i + l - 1;
            cost[i][j] = INT_MAX;

            for (int r = i; r <= j; r++) {
                int c = ((r > i) ? cost[i][r - 1] : 0) + ((r < j) ? cost[r + 1][j] : 0) + 
                        (i == 0 ? freq[j] : freq[j] - freq[i - 1]);
                if (c < cost[i][j])
                    cost[i][j] = c;
            }
        }
    }
    printf("Minimum cost of Optimal BST: %d\n", cost[0][n - 1]);
}

int main() {
    int n;
    printf("Enter the number of keys: ");
    scanf("%d", &n);

    int keys[n], freq[n];
    printf("Enter the keys and their frequencies:\n");
    for (int i = 0; i < n; i++)
        scanf("%d %d", &keys[i], &freq[i]);

    optimalBST(keys, freq, n);
    return 0;
}

