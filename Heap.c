#include <stdio.h>
#include <stdlib.h>

// Zero-indexed heap
void swap(int* A, int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void deleteLastElementFromArray(int* A, int* n) {
    (*n)--; 
}

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

    if (l < n && A[l] > A[swap_pos]) {  
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

// Delete the max element
void heapDelete(int* A, int* n) {
    swap(A, 0, *n - 1);      
    deleteLastElementFromArray(A, n);  
    maxHeapify(A, 0, *n);       
}

int main() {
    int A[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    int n = sizeof(A) / sizeof(A[0]); 

    buildMaxHeap(A, n);
    for (int j = 0; j < n; j++) {  
        printf("%d ", A[j]);
    }

    printf("\n");

    heapDelete(A, &n);
    for (int j = 0; j < n; j++) {  
        printf("%d ", A[j]);
    }

    return 0;
}
