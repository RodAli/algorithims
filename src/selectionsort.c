#include <stdio.h>

void selectionSort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        // Start the min element at current position
        int min_idx = i;

        // Loop through unsorted part of array and find min element
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Swap the min element with the current position
        int tmp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = tmp;
    }
}

/**
 * Prints out an array to std out.
 */
void printArray(int *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("\n\n");
}

int main() {
    
    int input_array[] = {9, 8, 2, 4, 10, 5, 7, 6, 3, 1, 7};
    int size = 10;

    printf("Before:\n");
    printArray(input_array, size);

    selectionSort(input_array, size);

    printf("After:\n");
    printArray(input_array, size);

    return 0;
}