//author: @kaspiotr (Piotr Kasprzyk)

#include <iostream>

using namespace std;

void printArray(int *A, int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << "\t";
    }
    cout << endl;
}

void merge(int A[], int B[], int i, int j, int k) {
    int left = i;
    int right =j;
    int b = i;

    while (left < j && right < k) {
        if (A[left] <= A[right]) {
            B[b++] = A[left++];
        } else {
            B[b++] = A[right++];
        }
    }

    while (left < j) B[b++] = A[left++];

    while (right < k) B[b++] = A[right++];

}

void mergeSort(int A[], int size) {
    if(size <=1) return;

    mergeSort(A, size/2);
    mergeSort(A+size/2, size - size/2);

    int *tmp = new int [size];

    merge(A, tmp, 0, size/2, size);

    for(int i=0; i<size; i++) {
        A[i] = tmp[i];
    }

    delete [] tmp;
}


int main() {
    int A[] = {9, 2, 3, 6, 5, 3, 10, 1, 7};
    int size = 9;
    printArray(A, size);
    mergeSort(A, size);
    printArray(A, size);
}
