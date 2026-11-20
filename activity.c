
#include <stdio.h>

int main() {
    int n, i, j, temp;
    int start[100], finish[100];
    int count = 0, lastFinish;

    printf("Enter number of activities: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("Invalid number of activities.\n");
        return 1;
    }

    printf("Enter start and finish times:\n");

    for (i = 0; i < n; i++) {
        scanf("%d %d", &start[i], &finish[i]);
    }

    // Sort by finish time
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (finish[j] > finish[j + 1]) {

                temp = finish[j];
                finish[j] = finish[j + 1];
                finish[j + 1] = temp;

                temp = start[j];
                start[j] = start[j + 1];
                start[j + 1] = temp;
            }
        }
    }

    printf("\nSelected activities:\n");

    // Select first activity
    printf("(%d, %d)\n", start[0], finish[0]);

    count = 1;
    lastFinish = finish[0];

    // Select remaining compatible activities
    for (i = 1; i < n; i++) {
        if (start[i] >= lastFinish) {
            printf("(%d, %d)\n", start[i], finish[i]);

            lastFinish = finish[i];
            count++;
        }
    }

    printf("\nMaximum number of activities: %d\n", count);
    printf("Name: Shourya Singh\n");

    return 0;
}
