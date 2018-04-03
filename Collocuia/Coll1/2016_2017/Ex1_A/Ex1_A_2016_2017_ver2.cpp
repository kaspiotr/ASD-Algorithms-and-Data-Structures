//
// Created by Karolina on 31.03.2018.
//

#include <iostream>
#include <string>
using namespace std;

//1. Dana jestr struktura opisująca listę jednokierunkową dla liczb rzeczywistych: struct Node{ Node* next; double value; }
//        Proszę zaimplementować funkcję void Sort( Node* list ),
//        która otrzymuje na wejściu listę liczb rzeczywistych (z wartownikiem),
//        wygenerowaną zgodnie z rozkładem jednostajnym na przedziale [0,10) i sortuje jej zawartość w kolejności niemalejącej.
//Funkcja powinna być możliwie jak najszybsza (biorąc pod uwagę warunki zadania). Proszę oszacować złożoność zaimplementowanej funkcji.


struct Node{
    double value;
    Node * next;
};
void insertionSort(Node *&first) {

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
//scalanie kubełków, dołączamy niepusty kubełek i przesuwamy się na jego koniec;
Node *merge_buckets(Node **bucket, int n){
    Node * result = new Node, *guard;
    guard = result;
    for(int i=0; i<n; i++){
        if(bucket[i]){
            result->next = bucket[i];
            while(result->next) result = result ->next;
        }
    }
    return guard->next;
}

void add_Node_at_start(Node *&first,Node *new_Node){
    new_Node->next = first;
    first = new_Node;

}

Node * sortList (Node *first){
    int n = 0;
    Node * guard = first;

    while(first){
        first = first->next;
        n++;
    }
    first = guard;
    if(n == 0) return NULL;

    Node ** bucket = new Node *[n];
    for(int i=0; i<n; i++){
        bucket[i] = new Node;
        bucket[i] = NULL;
    }
    Node * tmp = NULL;
    while(first){
        tmp = first;
        first = first->next;
        tmp->next = NULL;
        add_Node_at_start(bucket[((int)(tmp->value*n)/10)],tmp);     ////////
    }

    for(int i=0; i<n;i++) insertionSort(bucket[i]);

    first = merge_buckets(bucket, n);
    return first;
}

int main(){
    //zadanie numer 1
    cout<<"BucketSort"<<endl;
    Node *list= NULL;
    srand((unsigned)time(NULL));
    double value;
    for(int i = 10; i >0; i--){
        value= (double)(rand()%10);

        add(list,value);
    }
    print_l(list);
    sortList(list);
    cout << "Po posortowaniu:\n\n";
    print_l(list);
    cout << endl;
}