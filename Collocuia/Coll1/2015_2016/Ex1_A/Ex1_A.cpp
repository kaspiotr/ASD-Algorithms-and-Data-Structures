//author: @kaspiotr (Piotr Kasprzyk)

//Zad.1, kol1, gr. A, 2015/2016
//Prosze zaimplementowac funkcje void SumSort(int A[], int B[], int n). Funkcja ta przyjmuje na wejsciu dwie
//n^2 -elementowe tablice (A i B) i zapisuje w tablicy B taka permutacje elementow z A, że:
//
//suma elementow B[i] o indeksach od i=0 do i=n-1 jest <= suma elementow B[i] dla i = n do i=2n-1 <= ...
//... <= suma elementow B[i] dla i=n^2-n do i=n^2-1
//
//Prosze zaimplementowac funkcje SumSort tak, by dzialala mozliwie jak najszybciej. Prosze
//        oszacowac i podac jej zlozonosc czasowa.

#include <iostream>

using namespace std;

//Algorytm:
//1) Iterujemy po tablicy A[] obliczajac n sum (zlozonosc operacji: O(n^2)):
//      - elementow o indeksach od 0 do n-1
//      - elementow o indeksach od n do 2n-1
//      - ...
//      - elementow o indeksach od n^2-n do n^2-1
//   Jednoczesnie obliczane sumy umieszczamy w n-elementowej tablicy sums elementów struktury DivSum, ktora ma dwa pola:
//      - idx, w ktorym zapisujemy, ktora z kolejnych n sum obliczonych w kroku to jest,
//      - sum, w ktorym zapisujemy wartosc tej sumy
//2) Sortujemy tablice struktur DivSum algorytmem QuickSort wzgledem pola sum (zlozonosc operacji (n^2)*log(n^2), czyli
//   (2*(n^2)*log(n))
//3) Przepisujemy na podstawie informacji zawartych w posortowanej tablicy DivSum sums[n] zawartosc tablicy int A[] do
//   tablicy int B[] przepisujac odpowiednie przedzialy (zlozonosc operacji O(n^2)
//Zlozonosc calego algorytmu, to: O(n^2) + O(2*(n^2)*log(n) + 0(n^2), a zatem: O(n^2)*log(n))
#include <iostream>

using namespace std;

struct DivSum {
    int idx;
    int sum;
};

//funkcja pomocnicza do wyswietlania tablicy elementow struktury DivSum
void printDivSumTab(DivSum A[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "idx=" << A[i].idx << " sum=" << A[i].sum << ",\t";
    }
    cout << endl;
}

//funkcja pomocnicza do wyswietlania tablicy
void printTab(int A[], int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << "\t";
    }
    cout << endl;
}

void swap(DivSum *a, DivSum *b) {
    DivSum *tmp;
    tmp->idx = a->idx;
    tmp->sum = a->sum;

    a->idx = b->idx;
    a->sum = b->sum;

    b->idx = tmp->idx;
    a->sum = tmp->sum;
}

int Partition(DivSum A[], int p, int r) {
    int pivot = A[r].sum;
    int j = p - 1;

    for (int i = p; i < r; i++) {
        if (A[i].sum <= pivot) {
            j++;
            swap(A[j], A[i]);
        }
    }
    j++;
    swap(A[j], A[r]);

    return j;
}

void QuickSort(DivSum A[], int p, int r) {
    while (p < r) {
        int q = Partition(A, p, r);
        QuickSort(A, p, q - 1);
        p = q + 1;
    }
}

void SumSort(int A[], int B[], int n) {
    DivSum *sums = new DivSum[n];

    int idx = 0, sum = 0;

    for (int i = 0; i < n * n; i++) {
        if (idx != i / n) {
            sums[idx].sum = sum;
            sums[idx].idx = idx;
            idx++;
            sum = 0;
        }
        sum += A[i];
    }
    sums[idx].sum = sum;
    sums[idx].idx = idx;

    QuickSort(sums, 0, n - 1);

//    printDivSumTab(sums, 3);
    int idxB = 0;
    for (int i = 0; i < n; i++) {
        for (int j = sums[i].idx * n; j < (sums[i].idx + 1) * n; j++) {
            B[idxB++] = A[j];
        }
    }

    delete [] sums;
}

int main() {
//    Do testow:
//    DivSum sums[] = {{3,30}, {2,20}, {1,10}, {4,40}};
//    printDivSumTab(sums, 4);
//
//    QuickSort(sums, 0, 3);
//    printDivSumTab(sums, 4);
    int A[] = {3, 7, 1, 12, 2, 19, 2, 5, 6};
    int B[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    printTab(A, 9);
    SumSort(A, B, 3);
    printTab(B, 9);

    return 0;
}