//
// Created by Karolina on 01.04.2018.
//

//3. Dana jest struktura Node opisująca listę jednokierunkową:
//struct Node { Node * next; int value; };
//Proszę zaimplementować funkcję Node* fixSortedList( Node* L ),
//która otrzymuje na wejściu listę jednokierunkową bez wartowanika.
//Lista ta jest prawie posortowana w tym sensie, że powstała z listy posortowanej
//przez zmianę jednego losowo wybranego elementu na losową wartość.
//Funkcja powinna przepiąć elementy listy tak, by lista stała się posortowana i
//        zwrócić wskaźnik do głowy tej listy.
//Można założyć, że wszystkie liczby na liście są różne i że lista ma co najmniej dwa elementy.
//Funkcja powinna działać w czasie liniowym względem długości listy wejściowej.

//przechodząc 3 wskaźnikami wyszukujemy feralnego chujka, dzielimy według tego chujka listę na dwie posortowane i merge

struct Node {
    Node * next;
    int value;
};
void print_l(Node* l){
    while(l){
        cout << l->value << " ";
        l=l->next;
    }
    cout << endl;
}
void add(Node* &l,int value){
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
Node *mergeTwoLists(Node* &l1, Node* &l2) {
    Node *head = new Node;
    Node *p;
    head=p;
    Node *p1=l1;
    Node *p2=l2;
    while(p1!=NULL && p2!=NULL){
        if(p1->value < p2->value){
            p->next = p1;
            p1 = p1->next;
        }else{
            p->next = p2;
            p2 = p2->next;
        }
        p=p->next;
    }

    if(p1!=NULL){ //wersja bez wartownika, bo tutaj sie nie da
        p->next = p1;
    }

    if(p2!=NULL){
        p->next = p2;
    }

    return head->next;

}
Node* fixSortedList( Node* L ){

    //wyszukujemy zmienionej losowo wartości zaburzającej listę
    Node * head=L;
    Node * first=L->next;
    while(first->next!=NULL && L->value <first->value){
        L=L->next;
        first=first->next;
    }
    L->next = NULL;
    L=head;
    cout<<"Dwie tablice posortowane wynikające z podzielenia głównej"<<endl;
    print_l(L);
    print_l(first);
    cout<<"WYNIK"<<endl;
    return mergeTwoLists(L,first);
}
int main(){

    Node *list1=NULL;

    add(list1, 10);
    add(list1, 22);
    add(list1, 3);
    add(list1, 30);
    add(list1, 51);
    cout<<"Wyjściowa tablica"<<endl;
    print_l(list1);

    print_l(fixSortedList(list1));

    return 0;
}