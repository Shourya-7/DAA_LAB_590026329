
#include <stdio.h>
#include <limits.h>

#define MAX 100

int main()
{
    int n, p[MAX];
    int dp[MAX][MAX];
    int split[MAX][MAX];

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    if (n < 1 || n >= MAX)
    {
        printf("Invalid number of matrices.\n");
        return 1;
    }

    printf("Enter %d dimensions: ", n + 1);
    for (int i = 0; i <= n; i++)
    {
        scanf("%d", &p[i]);

        if (p[i] <= 0)
        {
            printf("Dimensions must be positive.\n");
            return 1;
        }
    }

    // Cost of multiplying one matrix is zero
    for (int i = 1; i <= n; i++)
        dp[i][i] = 0;

    // Chain length
    for (int length = 2; length <= n; length++)
    {
        for (int i = 1; i <= n - length + 1; i++)
        {
            int j = i + length - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++)
            {
                int cost = dp[i][k] +
                           dp[k + 1][j] +
                           p[i - 1] * p[k] * p[j];

                if (cost < dp[i][j])
                {
                    dp[i][j] = cost;
                    split[i][j] = k;
                }
            }
        }
    }

    printf("\nMinimum number of scalar multiplications: %d\n",
           dp[1][n]);

    printf("\nDP Cost Table:\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j < i)
                printf("-\t");
            else
                printf("%d\t", dp[i][j]);
        }
        printf("\n");
    }

    return 0;
}
