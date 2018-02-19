//author: @kaspiotr (Piotr Kasprzyk)

//Implementation of insertion sort algorithm on array of elements

#include <iostream>

using namespace std;

void printArray(int A[], int n) {
    for(int i=0; i<n; i++) {
        cout<<A[i]<<"\t";
    }
    cout<<endl;
}

void insertionSort(int A[], int n) {
    int j, tmp;
    for(int i=0; i<n; i++) {
        tmp = A[i];
        j = i-1;
        while(j >=0 && A[j] >tmp) {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=tmp;
    }
}

int main() {

    int A[]={5,2,4,6,1,3};
    int n=6;

    printArray(A, n);

    insertionSort(A, n);

    printArray(A, n);

    return 0;
}

