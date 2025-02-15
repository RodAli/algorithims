#include <stdio.h>

void insertionSort(int *arr, int n) {
    // i is pointing to number we want to 'insert' into sorted array
    for (int i = 1; i < n; i++) {
        // Value of the number in position i
        int key = arr[i];
        
        // arr[0 ... j] is the sorted part of the array
        int j = i - 1;

        // Move elements of the sorted array if they are larger than our key
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        // Insert our number in position i
        arr[j+1] = key;
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
    
    int input_array[] = {9, 8, 2, 4, 10, 5, 8, 6, 3, 1, 7};
    int size = 10;

    printf("Before:\n");
    printArray(input_array, size);

    insertionSort(input_array, size);

    printf("After:\n");
    printArray(input_array, size);

    return 0;
}