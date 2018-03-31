//author: @kaspiotr (Piotr Kasprzyk)

//Zad.2 gr. B, kol1, 2016/2017
//Prosze zaimplementowac funkcje algorytmiczna double AverageScore(double A[], int n, int lowest, int highest),
//ktora dostaje tablice double A[] rozmiaru n i dwa parametry: lowest i highest.
//Zadanie polega na obliczeniu sredniej wartosci w tablicy A[] z pominieciem lowest najmniejszych
//i highest najwiekszych elementow.

#include <iostream>

using namespace std;

//funckja pomocnicza wyswietlajaca zawartosc tablicy
void printTab(double A[], int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << "\t\t";
    }
    cout << endl;
}

//swap
void swap(double *a, double *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

//funckja partition wg Lomuto
int partition(double A[], int l, int r) {
    int pivot = A[r];
    int j = l - 1;

    for (int i = l; i < r; i++) {
        if (A[i] <= pivot) {
            j++;
            swap(A[j], A[i]);
        }
    }
    j++;
    swap(A[j], A[r]);
    return j;
}

//funckja select:
// argumenty:
// A -tablice,
// l -indeks pierwszego elementu tablicy,
// r -indeks ostatniego elementu tablicy,
// k -parametr mowiacy, ktory element co do wielkosci z nieposortowanej tablicy ma byc zwrocony
// zwraca:
// indeks k-tej co do wielkosci wartosci z nieposortowanej tablicy
// uwagi: funckja modyfikuje tablice
int select(double *A, int l, int r, int k) {
    if (l == r)
        return l;
    int q = partition(A, l, r);    // indeks podzialu

    int tmp = q - l + 1;    // liczba elementow w lewej podtablicy
    if (k == tmp) return q;
    else if (k < tmp) return select(A, l, q - 1, k);
    else return select(A, q + 1, r, k - tmp);
}

double AverageScore(double A[], int n, int lowest, int highest) {
    int firstIdx = select(A, 0, n - 1, lowest);
    int lastIdx = select(A, 0, n - 1, n - highest);

    double sum = 0.0;
    double noOfEls = 0.0;
    for (int i = firstIdx+1; i < lastIdx+1; i++) {
        sum += A[i];
        noOfEls++;
    }

    if (noOfEls == 0.0) return -1;
    return sum / noOfEls;
}

int main() {

    double A[] = {93.97, 0.5, 0.3, 0.7, 1.2, 2.3, 12.7, 10.7, 29.5, 6.7, 4.5};
    printTab(A, 11);
    cout << AverageScore(A, 11, 4, 3) << endl;
    return 0;
}