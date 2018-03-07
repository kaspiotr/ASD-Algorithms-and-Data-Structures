#include <iostream>
#include <string>
using namespace std;

void print(int A[],int s){
    for(int i=0;i<s;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}
//wersja z cormena
void Merge(int A[],int p,int q,int r){
    int s1=q-p+1;
    int s2=r-q;
    int i,j,k;
    int L[s1+1],R[s2+1];// dodatkowe miejsce dla wartownikow
    L[s1]=INT8_MAX;
    R[s2]=INT8_MAX;
    for( i=0; i<s1 ;i++)
        L[i] = A[p + i];
   // print(L,s1);
    for( j=0;j<s2;j++)
        R[j] = A[q + j+1];
    //print(R,s2);
    i=0,j=0,k=p;
    for(k=p;k<=r;k++){
        if(L[i]<=R[j]){
            A[k]=L[i];
            i++;
        }
        else{
            A[k]=R[j];
            j++;
        }
    }
   // print(A,r);
}
