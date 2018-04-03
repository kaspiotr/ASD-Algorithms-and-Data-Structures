//
// Created by Karolina on 02.04.2018.
//

#include<iostream>
#include <algorithm>
using namespace std;


int max(int a, int b) {
    if (a<b) return b;
    return a;
}

int Partition(int A[], int B[], int p, int r) // p - pocz¹tek przedzia³u, r = koniec
{
    int i=p;
    int j=r;
    int pivot=A[p];
    while(1)
    {
        while(A[i]<pivot) i++;
        while(A[j]>pivot) j--;
        if(i<j)
        {
            swap(A[i],A[j]);
            swap(B[i],B[j]);
            i++;
            j--;
        }
        else return j;
    }
}

void Quicksort(int a[], int b[], int left, int right) {
    if (left < right) {
        int k = Partition(a, b, left, right);
        Quicksort(a, b, left, k);
        Quicksort(a, b, k + 1, right);
    }
}


int largestIntersection(int a[], int b[], int n)
{

    Quicksort(a, b, 0, 3);		//sortujemy tablicê a rosn¹co i odpowiednio modyfikujemy Quicksorta ¿eby
    //od razu te¿ zamienia³ w tablicy b ¿eby nie straciæ przedzia³ów
    int c[4], d[4];				//¿eby mo¿na by³o swobodnie nadpisywaæ i nie traciæ oryginalnych danych
    for (int i = 0; i<n; i++) {
        c[i] = a[i];
        d[i] = b[i];
    }
    bool zmiana = false;
    int maks = 0;
    int licznik = 1;

    for (int i = 0; i<n; i++) {
        for (int j = i+1; j < n; j++) {
            //sprawdzamy czy kolejne a nie jest wiêksze od obecnego b
            if (d[i] > c[j]) {				//w przedzia³ach [1,10] [6,12] d[i] = 10, c[j] = 6;
                c[i] = c[j];				//jesli tak to tworzymy nowy przedzia³ -> [6,10]

                zmiana = true;
                //	cout<<d[i]<<" "<<c[j]<<endl;
            }
            if (d[i] > d[j]) {				//to samo robmy dla kolejnego b;
                d[i] = d[j];

                zmiana = true;
                //	cout<<d[i]<<" "<<d[j]<<endl;
            }
            if(zmiana) licznik++;
            zmiana = false;
        }
        maks = max(maks, licznik);
        licznik = 1;
    }

    return maks;
}

int main() {

    //int a[7] = {4,6,5,1,11,13,20};
    //int b[7] = {10,15,9,4,12,14,30};

    int x;
    //x= largestIntersection(a, b, 7);
    //cout << x<<endl;
    int a1[3] = {4,20,10};
    int b1[3] = {8,30,12};
    x = largestIntersection(a1, b1, 3);
    cout << x;

    return 0;
}





