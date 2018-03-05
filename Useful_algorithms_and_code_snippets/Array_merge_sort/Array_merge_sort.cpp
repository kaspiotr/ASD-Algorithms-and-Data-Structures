//author: @kaspiotr (Piotr Kasprzyk)

//Implementation of mergeSort algorithm on an array of elements
#include <iostream>

using namespace std;

void printArray(int *A, int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << "\t";
    }
    cout << endl;
}

void merge(int *A, int end1, int end2) {
    int i = 0;
    int j = end1;
    int k = 0;

    int *B = new int[end2];

    while (i < end1 && j < end2) {
        if (A[i] < A[j]) {
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
        }
    }

    while (i < end1) B[k++] = A[i++];

    while (j < end2) B[k++] = A[j++];

    for (int m = 0; m < end2; m++) A[m] = B[m];

    delete[] B;
}

void mergeSort(int *A, int size) {
    for (int end1 = 1; end1 < size; end1 *= 2) {
        for (int j = 0; j < size - end1; j += 2 * end1) {
            int end2 = (2 * end1 < size - j) ? 2 * end1 : size - j;
            merge(&A[j], end1, end2);
        }
    }
}

int main() {
    int A[] = {9, 2, 3, 6, 5, 3, 10, 1, 7};
    int size = 9;
    printArray(A, size);
    mergeSort(A, size);
    printArray(A, size);
}

