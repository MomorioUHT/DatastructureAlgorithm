#include <stdio.h>
#include <stdlib.h>

void swap(int* Arr, int a, int b) {
    int temp = Arr[a];
    Arr[a] = Arr[b];
    Arr[b] = temp;    
}

void insertionSort(int* Arr, int n) {
    for (int i = 1; i < n; i++) {
        //Store the current value, to prevent override
        int curr = Arr[i];
        int j = i - 1;

        //Shift left elements until its less than the current value
        while (j >= 0 && Arr[j] > curr) {
            Arr[j + 1] = Arr[j];
            j--;
        }

        //Insert the current value to blank space
        Arr[j + 1] = curr;
    }
}

void selectionSort(int* Arr, int n) {
    for (int i = 1; i < n; i++) {
        //Assume that i will be the min index
        int min_index = i;

        //Find the min index if have any;
        for (int j = i+1; j < n; j++) {
            if (Arr[j] < Arr[min_index]) {
                min_index = j;
            }
        }

        //Swap the value of min index with current value at index i
        swap(Arr, i, min_index);
    }
}

void bubbleSort(int* Arr, int n) {
    //Iterate in pairs
    for (int i = 1; i < n; i ++) {
        for (int j = 0; j < n-1; j++) {
            //Always compares the index at j and j+1 (further)
            if (Arr[j] > Arr[j + 1]) {
                swap(Arr, j, j+1);
            }
        }
    }
}

//Heap Sort
int left(int i) {
    return (2 * i) + 1;
}

int right(int i) {
    return (2 * i) + 2;
}

void maxHeapify(int* A, int i, int n) {
    int l = left(i);
    int r = right(i);
    int swap_pos = i;

    if (l < n && A[l] > A[i]) {  
        swap_pos = l;
    }
    if (r < n && A[r] > A[swap_pos]) {  
        swap_pos = r;
    }

    if (swap_pos != i) {
        swap(A, i, swap_pos);
        maxHeapify(A, swap_pos, n);
    }
}

void buildMaxHeap(int* A, int n) {
    for (int i = (n / 2) - 1; i >= 0; i--) {
        maxHeapify(A, i, n);
    }
}

void heapSort(int* A, int n) {
    buildMaxHeap(A, n);
    for (int i = n - 1; i > 0; i--) { 
        swap(A, 0, i);
        maxHeapify(A, 0, i);
    }
}

int main() {
    int n = 10;
    int A[] = {5, 10, 4, 6, 1, 3, 2, 9, 7, 8};

    insertionSort(A, n);
    for (int i = 0; i < n; ++i) {
        printf("%d ", A[i]);
    }

    printf("\n");
    //=================================================

    int m = 10;
    int B[] = {4, 3, 1, 5, 6, 7, 10, 2, 9, 8};    

    selectionSort(A, n);
    for (int i = 0; i < n; ++i) {
        printf("%d ", A[i]);
    }

    printf("\n");
    //=================================================

    int p = 10;
    int C[] = {5, 4, 6, 10, 3, 1, 7, 8, 2, 9}; 

    bubbleSort(A, n);
    for (int i = 0; i < n; ++i) {
        printf("%d ", A[i]);
    }

    printf("\n");
    //=================================================

    int q = 10;
    int D[] = {8, 1, 5, 9, 2, 4, 7, 10, 3, 6}; 

    heapSort(A, n);
    for (int i = 0; i < n; ++i) {
        printf("%d ", A[i]);
    }

    printf("\n");
}
