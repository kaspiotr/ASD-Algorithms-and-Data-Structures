//author: @kaspiotr (Piotr Kasprzyk)

/*
2. Pełna (wraz ze stosem) implementacja iteracyjnej wersji QuickSort-a
*/

//z wykorzystaniem stosu z STLa

#include <stack>
#include <iostream>

using namespace std;

void printTab(int A[], int size) {
    for (int i = 0; i < size; i++) {
        cout << A[i] << "\t";
    }
    cout << endl;
}

void swap(int A[], int i, int j) {
    int tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
}

int partition(int A[], int l, int r) {
    int pivot = A[r];
    int j = l - 1;

    for (int i = l; i < r; i++) {
        if (A[i] <= pivot) {
            j++;
            swap(A, i, j);
        }
    }

    j++;
    swap(A, j, r);
    return j;
}

void iterQuickSort(int A[], int l, int r) {
    stack<int> s;
    int q;
    s.push(l);
    s.push(r);

    while (!s.empty()) {
        r = s.top();
        s.pop();
        l = s.top();
        s.pop();

        q = partition(A, l, r);

        if (l < q - 1) {
            s.push(l);
            s.push(q - 1);
        }

        if (q + 1 < r) {
            s.push(q + 1);
            s.push(r);
        }
    }
}

int main() {

    int A[] = {5, 3, 11, 1, 15, 7, 3};

    printTab(A, 7);
    iterQuickSort(A, 0, 6);
    printTab(A, 7);

    return 0;
}

