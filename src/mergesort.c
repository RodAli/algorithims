#include <stdio.h>

/**
 * Merge both arrays into one
 */
void merge(int *arr, int left, int middle, int right) {

    int a_idx, b_idx, idx;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Temporary arrays
    int A[n1], B[n2];

    // Populate our temp arrays
    for (a_idx= 0; a_idx < n1; a_idx++) {
        A[a_idx] = arr[left + a_idx];
    }
    for (b_idx = 0; b_idx < n2; b_idx++) {
        B[b_idx] = arr[middle + 1 + b_idx];
    }

    a_idx = 0;
    b_idx = 0;
    idx = left;

    // Mere the temp arrays back into our initial array
    while (a_idx < n1 && b_idx < n2) {
        if (A[a_idx] <= B[b_idx]) {
            arr[idx] = A[a_idx];
            a_idx++;
        } else {
            arr[idx] = B[b_idx];
            b_idx++;
        }
        idx++;
    }

    // Merge in any leftover elements, if there are any
    while (a_idx < n1) {
        arr[idx] = A[a_idx];
        a_idx++;
        idx++;
    }

    // Merge in any leftover elements, if there are any
    while (b_idx < n2) {
        arr[idx] = B[b_idx];
        b_idx++;
        idx++;
    }
}

/**
 * Recursive merge sort.
 */
void _mergeSort(int *arr, int left, int right) {
    // Recurse until we our left >= right
    if (left < right) {
        int middle = left + (right - left) / 2;

        // Call merge sort on both halves of this array
        _mergeSort(arr, left, middle);
        _mergeSort(arr, middle + 1, right);

        // Merge sorted halves
        merge(arr, left, middle, right);
    }
}

/**
 * Merge sort wrapper.
 */
void mergeSort(int *arr, int n) {
    _mergeSort(arr, 0, n - 1);
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

    mergeSort(input_array, size);

    printf("After:\n");
    printArray(input_array, size);

    return 0;
}