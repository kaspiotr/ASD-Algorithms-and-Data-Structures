//
// Created by Karolina on 02.04.2018.
//

//
// Created by Karolina on 02.04.2018.
//

#include<iostream>
using namespace std;

//nie działa do końca poprawie niestety

//void swap(double x, double y){
//    double tmp = x;
//    x=y;
//    y=tmp;
//}

int max(int a, int b){
    if(a<b) return b;
    return a;
}
int Partition2(double A[], double B[], int p, int r) // p - początek przedziału, r = koniec
{
    int x = A[r]; // x to ostatni element
    int i = p - 1; // i ustawiamy przed przedziałem
    int j;
    for (j = p; j < r; j++) {
        if (A[j] <= x) // elementy mniejsze od x są przekładane na początek
        {
            i++;
            swap(A[i], A[j]);
            swap(B[i],B[j]);
        }
    }
    swap(A[r], A[i + 1]);
    swap(B[r],B[i+1]);
    return i + 1;
}
int Partition(double a[], double b[], int left, int right){

    double q = a[(left+ right)/2];
    int i = left;
    int j = right;

    while(i<j){
        while(a[j--] > q);
        while(a[i++] < q);
        if(i<j){
            swap(a[i], a[j]);
            swap(b[i], b[j]);
        }
    }
    return j;
}


void Quicksort(double a[], double b[], int left, int right){

    if(left<right){
        int k = Partition2(a,b,left,right);
        Quicksort(a,b,left,k-1);
        Quicksort(a,b,k+1,right);
    }

}
void print(double A[],int s){
    for(int i=0;i<s;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int largestIntersection(double a[], double b[], int n)
{

    //  print(a,n);
    //  print(b,n);
    Quicksort(a,b,0,n-1);		//sortujemy tablicê a rosn¹co i odpowiednio modyfikujemy Quicksorta ¿eby
    //od razu te¿ zamienia³ w tablicy b ¿eby nie straciæ przedzia³ów
    // print(a,n);
    //print(b,n);

    double c[n], d[n];			//¿eby mo¿na by³o swobodnie nadpisywaæ i nie traciæ oryginalnych danych
    for(int i = 0; i<n;i++){
        c[i] = a[i];
        d[i] = b[i];
    }

    int maks = 0;
    int licznik = 1;

    for(int i = 0; i<n-1; i++){
        for(int j = i+1; j < n; j++){
            //sprawdzamy czy kolejne a nie jest wiêksze od obecnego b
            if(d[i]>=c[j]){				//w przedzia³ach [1,10] [6,12] d[i] = 10, c[j] = 6;
                //jesli tak to tworzymy nowy przedzia³ -> [6,10]
                licznik++;
            }
            if (d[i] > d[j]) {
                licznik++;
            }

            if(d[i] < d[j]){				//to samo robmy dla kolejnego b;
                //  d[i] = d[j];
                //     cout<<d[i]<<" "<<d[j]<<endl;
                licznik--;
            }

        }

        maks = max(maks, licznik);
        licznik=1;
    }
    // print(c,n);
    // print(d,n);

    return maks;
}

int main(){


    double a1[7]={4,6,5,1,11,13,20};
    double b1[7]={10,15,9,4,12,14,30};

    int x= largestIntersection(a1,b1,7);
    cout<<x<<endl;
    double a[3] = {4,20,10};
    double b[3] = {8,30,12};
    x = largestIntersection(a, b, 3);
    cout << x;
    return 0;
}



