#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {

            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void checkTime(int n) {
    int arr[n];

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }

    clock_t start, end;

    start = clock();
    bubbleSort(arr, n);
    end = clock();

    printf("Time for %d inputs = %lf seconds\n",
           n, (double)(end - start) / CLOCKS_PER_SEC);
}

int main() {
    srand(time(NULL));

    int arr[] = {34, 7, 25, 12, 99, 1, 56, 18, 43, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bubbleSort(arr, n);

    printf("\n\nSorted array:\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\nTime Analysis:\n");

    checkTime(10);
    checkTime(100);
    checkTime(1000);

    printf("\nName: Shourya Singh\n");

    return 0;
}
