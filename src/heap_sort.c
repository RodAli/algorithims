#include <stdio.h>

/**
 * Heapify arr with size n at root
 */
void heapify(int *arr, int n, int root) {
    int largest = root;

    int left = 2 * root + 1;
    int right = 2 * root + 2;

    // If our left child is larger than our root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If our right child is larger than our root
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If our root is not the largest
    if (largest != root) {
        // Swap largest child with root
        int tmp = arr[root];
        arr[root] = arr[largest];
        arr[largest] = tmp;

        // Recursively call on affected sub-tree
        heapify(arr, n, largest);
    }
}

/**
 * Heapsort main function
 */
void heapsort(int *arr, int n) {

    // Start at the last non-leaf node and heapify the array
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        // Extact the max from the heap and swap with the last element
        int tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;

        // Re-heapify the array
        heapify(arr, i, 0);
    }
}

/**
 * Prints out an array to std out
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

    heapsort(input_array, size);

    printf("After:\n");
    printArray(input_array, size);

    return 0;
}