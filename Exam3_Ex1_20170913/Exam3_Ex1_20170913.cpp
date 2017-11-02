//author: @kaspiotr (Piotr Kasprzyk)

/*
[2pkt.] Zadanie 1. Dany jest ciag [a1,b1],...,[an,bn] przedzialow domknietych. Prosze zaimplementowac funkcje:

int lergestInstersection(double a[], double b[], n);

ktora zwraca najwieksza liczbe przedzialow, ktore maja niepuste przeciecie. Np. dla przedzialow
[1,10],[6,12],[2,5],[9,11] odpowiedz to 3 (poniewaz [1,10] and [6,12] and [9,11] = [9,10]). Prosze takze
opisac algorytm w kilku zdaniach i podac jego zlozonosc czasowa.
 */

/*
Algorytm:
1.Tworzymy strukture Point, ktora uzupelnimy na podstawie tablicy poczatkow
  przedzialow a[] oraz tablicy koncow przedzialow b[]. Struktura ta pozwoli
  nam zapamietac, ktory punkt jest poczatkiem, a ktory koncem przedzialu.
  Zlozonosc operacji: Theta(n), gdzie n to rozmiar tablic a[] i b[].
2.Sortujemy tablice elementow typu Point -tak, zeby punkty w niej zapisane
  byly ulozone w kolejnosci niemalejacej (jak na osi wpsolrzednych).
  Sortowanie wykonujemy algorytmem QuickSort, a zatem zlozonosc tej operacji
  wynosi Theta(nlog(n))
3.Tworzymy zmienna counter -czyli licznik, ktory bedzie mowil ile przedzialow
  w danym punkcie osi liczbowej ma czesc wspolna.
4.Przechodzimy od lewej do prawej i zapamietujemy maksymalna wartosc zmiennej
  counter, ktora pozniej zwroci funcja largestItersection.

Zlozonosc algorytmu jest rzedu: Theta(nlog(n)).
 */

#include <iostream>

using namespace std;

struct Point{
    double x;
    int val; //val=1 -poczatek przedzialu, val=-1 -koniec przedzialu
};

//funckja pomocnicza
void printTabPoint(Point A[], int size){

    for(int i=0; i<size; i++){
        cout<<i<<") x="<<A[i].x<<"\t val="<<A[i].val<<endl;
    }
    cout<<endl;
}

void swap(Point &a, Point &b){
    double tmpX = a.x;
    int tmpVal = a.val;
    a.x = b.x;
    a.val = b.val;
    b.x = tmpX;
    b.val = tmpVal;
}

int Partition(Point A[], int p, int r){
    double pivot = A[r].x;

    int j=p-1;

    for(int i=p; i<r; i++){
        if(A[i].x <= pivot){
            j++;
            swap(A[j],A[i]);
        }
    }
    j++;
    swap(A[j],A[r]);

    return j;
}

void QuickSort(Point A[], int p, int r){
    while(p<r){
        int q = Partition(A,p,r);
        QuickSort(A,p,q-1);
        p=q+1;
    }
}

int largestInstersection(double a[], double b[], int n){

    Point *A = new Point [2*n];

    //utworzenie tablicy elementow typu Point
    int j=0;
    for(int i=0; i<2*n; i+=2){
        A[i].x = a[j];
        A[i].val = 1;
        A[i+1].x = b[j];
        A[i+1].val = -1;
        j++;
    }

    //printTabPoint(A,2*n); debuging

    //sortowanie tablicy Point[]
    QuickSort(A,0,2*n-1);

    //printTabPoint(A,2*n); debuging

    int counterMax = 0, counter = 0;

    for(int i=0; i<2*n; i++){
        if(A[i].val == 1) counter++;
        else counter--;

        if(counterMax < counter) counterMax = counter;
    }

    delete [] A;

    return counterMax;
}

int main(){

    const int n = 4;
    double a[]={ 1, 6, 2, 9};
    double b[]={10,12, 5,11};

    //dla podanego zestawu danych a[] i b[] wynik powinien wynosic 3
    cout<<largestInstersection(a,b,n)<<endl;

    return 0;
}
