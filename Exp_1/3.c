#include <stdio.h>

int main() {
    int n, i;
    int arr[100];
    int largest;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    largest = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }

    printf("Largest number = %d\n", largest);

    printf("\nName: Shourya Singh\n");

    return 0;
}
