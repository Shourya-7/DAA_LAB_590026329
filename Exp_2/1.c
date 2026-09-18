#include <stdio.h>
#include <time.h>

void insertionSort(int arr[], int n) {
    int i, j, key;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void checkTime(int n) {
    int arr[n];

    for (int i = 0; i < n; i++) {
        arr[i] = n - i;
    }

    clock_t start, end;

    start = clock();
    insertionSort(arr, n);
    end = clock();

    printf("Time for %d inputs = %lf seconds\n",
           n, (double)(end - start) / CLOCKS_PER_SEC);
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    insertionSort(arr, n);

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
