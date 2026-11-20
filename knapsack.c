
#include <stdio.h>

#define MAX 100
#define MAX_CAPACITY 1000

int main() {
    int n, W, i, w;
    int weight[MAX], value[MAX];
    int dp[MAX + 1][MAX_CAPACITY + 1];

    printf("Enter number of items: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid number of items.\n");
        return 1;
    }

    printf("Enter capacity of knapsack: ");
    scanf("%d", &W);

    if (W < 0 || W > MAX_CAPACITY) {
        printf("Invalid capacity.\n");
        return 1;
    }

    printf("Enter weight and value of each item:\n");

    for (i = 1; i <= n; i++) {
        scanf("%d %d", &weight[i], &value[i]);

        if (weight[i] < 0 || value[i] < 0) {
            printf("Invalid item data.\n");
            return 1;
        }
    }

    // Initialize and fill DP table
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {

            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            }

            else if (weight[i] <= w) {

                int include = value[i] +
                    dp[i - 1][w - weight[i]];

                int exclude = dp[i - 1][w];

                if (include > exclude)
                    dp[i][w] = include;
                else
                    dp[i][w] = exclude;
            }

            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    printf("\nMaximum value: %d\n", dp[n][W]);

    printf("\nSelected items:\n");

    w = W;

    for (i = n; i > 0; i--) {

        if (dp[i][w] != dp[i - 1][w]) {

            printf("Item %d: Weight = %d, Value = %d\n",
                   i, weight[i], value[i]);

            w = w - weight[i];
        }
    }

    printf("\nName: Shourya Singh\n");

    return 0;
}
