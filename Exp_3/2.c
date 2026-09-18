#include <stdio.h>

int binarySearch(int arr[], int low, int high, int target) {

    if (low > high) {
        return -1;
    }

    int mid = (low + high) / 2;

    if (arr[mid] == target) {
        return mid;
    }

    else if (target < arr[mid]) {
        return binarySearch(arr, low, mid - 1, target);
    }

    else {
        return binarySearch(arr, mid + 1, high, target);
    }
}

int main() {

    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72};

    int n = sizeof(arr) / sizeof(arr[0]);

    int target = 38;

    int result = binarySearch(arr, 0, n - 1, target);

    if (result != -1) {
        printf("Element found at index %d\n", result);
    }
    else {
        printf("Element not found\n");
    }

    printf("\nName: Shourya Singh\n");

    return 0;
}
