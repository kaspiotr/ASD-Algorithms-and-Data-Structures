//
// Created by Karolina on 31.03.2018.
//

int main(){
    //Zadanie numer 2
    cout<<"Suma pomiędzy kolejnymi wartosciami w tablicy"<<endl;
    int T1[4]={10, 7, 6, 15};
    //cout<<select(T1,0,3,1);
    cout<<SumBetween(T1,3,4,4);
    return 0;
}
//2. Proszę zaimplementować funkcję: int SumBetween(int T[], int from, int to, int n);
// Zadaniem tej funkcji jest obliczyć sumę liczb z n elementowej tablicy T,
// które w posortowanej tablicy znajdywałyby się na pozycjach o indeksach od from do to (włącznie).
// Można przyjąć, że liczby w tablicy T są parami różne (ale nie można przyjmować żadnego innego rozkładu danych).
// Zaimplementowana funkcja powinna być możliwie jak najszybsza. Proszę oszacować jej złożoność czasową
// (oraz bardzo krótko uzasadnić to oszacowanie).

int Partition( int A[], int p, int r){
    int i,j;
    int x=A[r];
    i=p-1;
    for(j=p; j<r ;j++){
        if(A[j]<=x) {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[r],A[i+1]);
    return i+1;
}

int select(int A[], int p, int r, int k){
    if(p == r) return p;
    int q=Partition(A,p,r);
    int tmp = q-p+1;
    if(tmp == k) return q;
    if(k < tmp) return select(A,p,q-1,k);
    else return select(A,q+1,r,k-tmp);
}
int SumBetween(int T[], int from, int to, int n){
    int p = select(T,0,n-1,from);
    cout<<p<<endl;
    int k = select(T,0,n-1,to);
    cout<<p<<" "<< k<<endl;
    int sum = 0;
    for(int i=p; i<=k ;i++)
        sum += T[i];
    return sum;

}