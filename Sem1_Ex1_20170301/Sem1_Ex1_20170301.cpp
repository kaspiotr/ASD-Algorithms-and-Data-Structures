//author: @kaspiotr (Piotr Kasprzyk)

/*
Zad.1, Cw.1, ASD, 1.03.17
Zaimplementowac sortowanie przez wstawianie
 */

#include <iostream>

using namespace std;

void printTab(int A[], int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << "\t";
    }
    cout << endl;
}

void insertSort(int A[], int n) {
    int tmp, j; //j-indeks wskazujacy karte biezaca

    for (int i = 1; i < n; i++) {
        tmp = A[i];
        j = i - 1;

        while (j >= 0 && A[j] > tmp) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = tmp;
    }
}

int main() {

    int N = 5;
    int tab[] = {5, 2, 4, 0, 1, 3};

    printTab(tab, N);

    insertSort(tab, N);

    printTab(tab, N);

    return 0;
}