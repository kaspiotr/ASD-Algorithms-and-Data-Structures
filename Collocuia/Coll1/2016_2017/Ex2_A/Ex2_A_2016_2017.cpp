//author: @kaspiotr (Piotr Kasprzyk)

//Zad.2 gr. A, kol1, 2016/2017
//Prosze zaimplementowac funkcje:
//int SumBetween(int T[], int from, int to, int n);
//Zadaniem tej funkcji jest obliczyc sume liczb z n elementowej tablicy T, ktore w posortowanej
//tablicy znajdowalyby sie na pozycjach o indeksach od from do to (wlacznie). Mozna przyjac, ze
//liczby w tablicy T sa parami rozne (ale nie mozna przyjmowac zadnego innego rozkladu danych).
//Zaimplementowana funkcja powinna być mozliwie jak najszybsza. Prosze oszacowac jej zlozonosc
//czasowa (oraz bardzo krotko uzasadnic to oszacowanie).

#include <iostream>

using namespace std;

//funckja pomocnicza wyswietlajaca zawartosc tablicy
void printTab(int A[], int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << "\t";
    }
    cout << endl;
}

//swap
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

//funckja partition wg Lomuto
int partition(int A[], int l, int r) {
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
int select(int *A, int l, int r, int k) {
    if (l == r)
        return l;
    int q = partition(A, l, r);    // indeks podzialu

    int tmp = q - l + 1;    // liczba elementow w lewej podtablicy
    if (k == tmp) return q;
    else if (k < tmp) return select(A, l, q - 1, k);
    else return select(A, q + 1, r, k - tmp);
}

int SumBetween(int T[], int from, int to, int n) {

    int fromIdx = select(T, 0, n - 1, from);
//    printTab(T, 15);
    int toIdx = select(T, 0, n - 1, to);
//    printTab(T, 15);

    int sum = 0;
    for (int i = fromIdx; i <= toIdx; i++) //fromIdx = from-1 , a toIdx = to-1
        sum += T[i];
    return sum;
}

int main() {

    int A[] = {13, 9, 93, 5, 3, 17, 22, 6, 4, 33, 12, 15, 10, 11, 7}; //bez powtorek, bo elementy tablicy moga byc parami rozne
    printTab(A, 15);
    cout<<SumBetween(A, 2, 5, 15)<<endl;
//    printTab(A, 15);
    return 0;
}

//Zlozonosc czasowa funkcji SumBetween, to:
//- zlozonosc czasowa select'a to w najgorszym wypadku O(n),
//- w funkcji SumBetween dwa razy wykonywana jest funkcja select,
//- na koncu sumowane sa elementy od from do to wlacznie, co tez ma w najgorszym przypadku zlozonosc czasowa O(n)
//
//Ostatecznie zlozonosc czasowa funkcji SumBetween wynosi O(n)
