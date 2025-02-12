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
 * Main bubble sort algorithm. Takes in an array and sorts it in place.
 */
void bubbleSort(int *arr, int n) {
    
    int i, j, tmp, swapped;

    // Outer loop
    for (i = 0; i < n; i++) {
        swapped = 0;
        
        // Inner loop - "bubble up" the highest element
        for (j = 0; j < n - i - 1; j++) {
            
            // Check if we need to swap
            if (arr[j] > arr[j+1]) {

                // Swap
                swap(&arr[j], &arr[j+1]);
                swapped = 1;
            }
        }    

        // If there were no swaps on the last inner loop, then we are done
        if (swapped == 0) {
            break;
        }
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
    
    int input_array[] = {2, 4, 5, 3, 1} ;
    int size = 5;

    printf("Before:\n");
    printArray(input_array, size);

    bubbleSort(input_array, size);

    printf("After:\n");
    printArray(input_array, size);

    return 0;
}
