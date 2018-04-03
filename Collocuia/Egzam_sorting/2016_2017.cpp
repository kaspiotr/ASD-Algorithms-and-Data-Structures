//
// Created by Karolina on 02.04.2018.
//

//
// Created by Karolina on 02.04.2018.
//

#include <iostream>
#include <string>
using namespace std;
//Zadanie 1. Dana jest struktura opisująca listę jednokierunkową przechowującą liczby typu double:
//struct Node { Node* next; double value; };
//Proszę zaimlementować funkcję Node* sortList( Node* L ), która sortuje listę wejściową w kolejności nierosnącej
//        i zwraca wskaźnik na element, który po posortowaniu został głową tej listy (wejściowa lista nie ma wartownika).
//Funkcja powinna być możliwie jak najszybsza (wiadomo, że liczby w wejściowej liście zostały wygenerowane zgodnie z
//rozkładem jednostajnym na przedziale (0,4)).

struct Node {
    Node* next;
    double value;
};

void insSort(Node * &first){
    if (first == NULL || first->next == NULL) return;

    Node *last = first, *curr = first->next;
    Node *p, *prev;

    while (curr != NULL) {
        p = first, prev = NULL;
        while (p != NULL && p != curr && p->value < curr->value) {
            prev = p;
            p = p->next;
        }

        if (p == curr) {
            last = curr;
        } else if (p == first) {
            last->next = curr->next;
            curr->next = first;
            first = curr;
        } else {
            last->next = curr->next;
            prev->next = curr;
            curr->next = p;
        }

        curr = last->next;
    }
}
Node *mergebuckets(Node **bucket, int n){
    Node * result=new Node;
    Node * guard = result;
    for(int i=0;i<n;i++){
        if(bucket[i]){
            result->next=bucket[i];
            while(result->next) result=result->next;
        }
    }
    return guard;
}

void add(Node* &l,double value){
    Node* temp=l;
    if(temp){
        while(temp->next) temp=temp->next;
        temp->next=new Node;
        temp->next->value=value;
        temp->next->next=NULL;
    } else {
        l=new Node;
        l->value=value;
        l->next=NULL;
    }
}

void print_l(Node* list){
    Node * l= list;
    while(l){
        cout << l->value << " ";
        l=l->next;
    }
    cout << endl;
}
void add_Node_at_start(Node *&first,Node *new_Node){
    new_Node->next = first;
    first = new_Node;

}
Node* sortList( Node* L ){
    Node * first;
    first = L;
    int n=0;
    while(first){
        first=first->next;
        n++;
    }

    first=L;
    if(n==0) return NULL;
    Node ** bucket = new Node *[n];
    for(int i =0;i<n;i++){
        bucket[i]=new Node;
        bucket[i]=NULL;
    }
    Node * tmp=new Node;
    //print_l(first);

    while(first){
        print_l(first);
        tmp = first;
        first=first->next;
        tmp->next=NULL;

        add_Node_at_start(bucket[((int)(tmp->value*n)/10)],tmp);
        //print_l(first);
    }
    for(int i=0;i<n;i++) {
        //  print_l(bucket[i]);
        insSort(bucket[i]);
    }
    first=mergebuckets(bucket,n);
    return first;
}



//Dany jest ciąg [a1..b1],....,[an,bn] przedziałów domkniętych. Proszę zaimplementować funkcję:
//int largestIntersection(double a[],double b[],int n);
//która zwraca największą liczbę przedziałów, które mają nie puste przecięcie.Np dla przedziałów
//[1,10],[6,12],[2,5],[9,11] odp to 3 ponieważ [9,10] .Proszę także opisać alg w kilku zdaniach
//i podać złoż czasowa.
//tworzymy strukture w której będziemy zapamiętywać początek i koniec przedziału
//posortujemy strukture według początków przedziałów,
//będziemy parami sprawdzać czy przedzialy się pokrywają na zasadzie [max(a),min(b)] jeśli max(a)<min(b) to ++
struct interval{
    double a;
    double b;
};
void print(interval A[],int s){
    for(int i=0;i<s;i++){
        cout<<A[i].a<<" ";

    }
    cout<<endl;
    for(int i=0;i<s;i++){
        cout<<A[i].b<<" ";

    }
    cout<<endl;
}
void merge(interval A[], int p, int q,int r){

    int ip=p;
    int ir=q+1;
    int i=0;
    interval * B=new interval[r-p];
    while(ip<=q && ir<=r){
        if(A[ip].a<A[ir].a){
            B[i]=A[ip];
            ip++;
        }
        else{
            B[i]=A[ir];
            ir++;
        }
        i++;
    }
    if(ip<=q)
        while(ip<=q) B[i++]=A[ip++];
    else
        while(ir<=r)  B[i++]=A[ir++];

    for(i=0;i<=r-p;i++) A[p+i]=B[i];
}

void MergeSort(interval A[],int p, int r){
    int q;
    if(p<r){
        q=(p+r)/2;
        MergeSort(A,p,q);
        MergeSort(A,q+1,r);
        merge(A,p,q,r);
    }
}
double max_d(double x, double y){
    if(x>y) return x;
    else return y;
}
double min_d(double x, double y){
    if(x<y) return x;
    else return y;
}
int largestIntersection(double a[],double b[],int n){
    interval *intervals =new interval[n];
    for(int i=0;i<n;i++){
        intervals[i].a=a[i];
        intervals[i].b=b[i];
    }
//sortujemy według początków przedziału i zapamiętujemy ich końce
    print(intervals,n);
    MergeSort(intervals,0,n-1);
    print(intervals,n); cout<<" ";
    //print(intervals->b,n);
    int max_interval=0;
    int j=2;
    interval k,l,m;
    k.a=0;k.b=0;
    l.a=max_d(intervals[1].a,intervals[0].a); //przypisujemy do zmiennej wartość przecięcia
    l.b=min_d(intervals[1].b,intervals[0].b);
    m.a=0,m.b=0;//do przechowywania finalnego przedzialu
    for(int i=2;i<n;i++){//warunek na przecinanie jest ok, ale nie działa dobrze, np dla [1,4],[4,10],[5,9] zwraca 3 a powinno 2
        k.a=max_d(intervals[i].a,intervals[i-1].a); //przypisujemy do zmiennej wartość przecięcia
        k.b=min_d(intervals[i].b,intervals[i-1].b);

        if(k.a<=k.b && l.a <= k.a && l.b >= k.b) {//jeżeli poprzedni nachodzący mieści się w kolejnym, kontynujemy przedział
            cout << k.a << " " << k.b << endl;
            j++;
            l.a = max_d(l.a, k.a);
            l.b = min_d(l.b, k.b);
            cout << "Kontynuacja: "<<l.a << " " << l.b << endl;
        }
        else if(k.a<=k.b && !(l.a <= k.a && l.b >= k.b) ){
            //jeżeli poprzedni nachodzacy nie miesci się w kolejnym
            l.a = k.a;
            l.b = k.b;
            j=2; //bo dwa przedziały się przecinają
            cout << "Nachodzący nowy: "<<l.a << " " << l.b <<endl;
        }
        if(max_interval<j){
            m.a=l.a;
            m.b=l.b;
            max_interval=j;
        }



    }
    cout<<"Ilość przecinających się przedziałów"<<" "<<max_interval<<endl;
    cout<<"Dla przedziału"<<"["<<m.a<<" ,"<<m.b<<"]"<<endl;
}
int main() {
   // zadanie numer 1
    cout << "BucketSort" << endl;
    Node *list = NULL;
    srand((unsigned) time(NULL));
    double value;
    for (int i = 15; i > 0; i--) {
        value = (double) (rand() % 40)/10;

        add(list, value);
    }
    print_l(list);
    sortList(list);
    cout << "Po posortowaniu:\n\n";
    print_l(list);
    cout << endl;
    //Zadanie drugie, ciągi
    double a[7]={4,6,5,1,11,13,9};
    double b[7]={10,15,9,4,12,14,9};

    largestIntersection(a,b,7);

    double a1[4]={1,2,4,6};
    double b1[4]={10,3,5,7};
    largestIntersection(a1,b1,4);
}