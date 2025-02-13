#include <stdio.h>

/**
 * Swaps two integer values.
 */
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * Partition function chooses this last element as the pivot.
 * Puts all elements less than the pivot on the left of the 
 * pivot and all elements equal or greater to the right.
 * Returns the location of the pivot in the array.
 */
int partition(int *arr, int first, int last) {
    
    // Choose the last element as our pivot
    int pivot = arr[last];

    // Stores where we insert elements less than our pivot
    int i = first - 1;

    // Loop from first to second last element
    for (int j = first; j <= last - 1; j++) {
        // If this element is less than our pivot
        if (arr[j] < pivot) {
            // Increment our insert location
            i++;
            // Swap this element to our insert location
            swap(&arr[i], &arr[j]);
        }
    }

    // Finally insert our pivot into the array
    swap(&arr[i+1], &arr[last]);
    return i + 1;
}

/**
 * Internal recursive quicksort.
 */
void _quicksort(int *arr, int first, int last) {
    // Recurses until first >= last
    if (first < last) {

        // Partitions the array
        int pivot_idx = partition(arr, first, last);

        // Run quick sort on elements less than pivot
        _quicksort(arr, first, pivot_idx - 1);
        
        // Run quick sort on lements greater than pivot
        _quicksort(arr, pivot_idx + 1, last);
    }
}

/**
 * Quicksort wrapper.
 */
void quicksort(int *arr, int n) {
    int first = 0;
    int last = n - 1;

    _quicksort(arr, first, last);
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

    quicksort(input_array, size);

    printf("After:\n");
    printArray(input_array, size);

    return 0;
}