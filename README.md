## Algorithms

This repository is an ongoing personal project aimed at learning common computer science algorithms and data structures. Each algorithm is implemented in a self-contained C program, which can be compiled and used individually.

The primary goal is not to achieve the most efficient implementation, but rather to serve as a learning tool for myself and a reference for others.

### Current implementations

#### Sorting Algorithms
- [Bubble Sort](src/bubble_sort.c)
- [Selection Sort](src/selection_sort.c)
- [Insertion Sort](src/insertion_sort.c)
- [Merge Sort](src/merge_sort.c)
- [Quick Sort](src/quick_sort.c)
- [Heap Sort](src/heap_sort.c)

#### Search Algorithms

TODO

#### Data Structures

- [Linked List](src/linked_list.c)

### Usage

To compile and run yourself:

1. Clone the repo:

    ```bash
    git clone https://github.com/RodAli/algorithims.git
    ```

2. You can use the Makefile to compile all the C programs into their own runnable executables.
In your preferred terminal, navigate to the root directory of your local repo and run:

    ```bash
    make
    ```

3. Compiled machine code should be outputted into folder called out. To run any program, lets say bubble sort, run:

    ```bash
    ./out/bubblesort
    ```

You are done!