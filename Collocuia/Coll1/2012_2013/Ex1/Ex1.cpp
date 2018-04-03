//author: @kaspiotr (Piotr Kasprzyk)

//Zad.1, kol1, 2012/2013
//1. Prosze zaimplementowac funkcje sortujaca (rosnaco) liste jednokierunkowa metoda
//QuickerSort. Algorytm QuickerSort to odmiana algorytmu QuickSort, w ktorej funkcja
//podzialu dzieli sortowane dane według przyjetej wartości x na trzy grupy: mniejsze od x, rowne
//x, oraz wieksze od x. Nastepnie rekurencyjnie sortowane są grupy pierwsza i trzecia. Panstwa
//funkcja powinna miec następujacy prototyp:
//struct Node { Node* next; int val; };
//Node* QuickerSort ( Node* head )
//Argumentem funkcji jest wskaznik na glowe listy do posortowania a wynikiem powinien byc
//wskaznik na glowe listy posortowanej. Sortowanie powinno polegac na porownywaniu wartosci
//val list oraz przepinaniu wskaznikow next.

#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

struct Node {
    int value;
    Node *next;
};

//funkcja pomocnicza do wyswietlania listy jednokierunkwej
void printList(Node *first) {
    while (first != NULL) {
        cout << first->value << "\t";
    }
    cout << endl;
}

//funckja dodajaca nowy Node do listy jednokierunkowej na jej poczatek
void addNodeToList(Node* &head, int v) {
    Node *newNode = new Node;
    newNode->value = v;
    newNode->next = head;
    head = newNode;
}

//funkcja tworzaca losowa liste jednokierunkowa o podanej dlugosci n
Node* makeRandomList(int n) {
    srand(time(NULL));
    Node *head = NULL;
    for (int i = 0; i < n; i++) addNodeToList(head, rand() % 10);
    return head;
}

void addNodeToListAtEnd(Node* &head, int value) {
    Node *tmp = new Node, *tail = head;
    tmp->value = value;
    tmp->next = NULL;
    if (tail != NULL) {
        while (tail->next != NULL) tail = tail->next;
        tail->next = tmp;
    } else head = tmp;
}

//funkcja odpinajaca glowe listy jednokierunkowej
int getHead(Node *&head) {
    int headValue;
    if (head->next != NULL) {
        headValue = head->value;
        head = head->next;
    } else {
        headValue = head->value;
        head = NULL;
    }
    return headValue;
}

//funckja laczaca trzy listy jednokierunkowe w jedna w kolejnosci list1->list2->list3
Node *combine(Node *list1, Node *list2, Node *list3) {
    Node *tail1 = list1, *tail2 = list2;
    while (list1 != NULL && tail1->next != NULL) tail1 = tail1->next;
    while (list2 != NULL && tail2->next != NULL) tail2 = tail2->next;
    if (list1 != NULL) {
        tail1->next = list2;
        tail2->next = list3;
        return list1;
    } else {
        tail2->next = list3;
        return list2;
    }
}

Node *QuickerSort(Node *head) {
    if (head == NULL) return head;
    int pivot = getHead(head), tmp;
    Node *list1 = NULL, *list2 = NULL, *list3 = NULL;
    addNodeToListAtEnd(list2, pivot);
    while (head != NULL) {
        tmp = getHead(head);
        if (tmp < pivot) addNodeToListAtEnd(list1, tmp);
        else if (tmp > pivot) addNodeToListAtEnd(list3, tmp);
        else addNodeToListAtEnd(list2, tmp);
    }
    return combine(quickSortList(list1), list2, quickSortList(list3));
}

int main() {
    int n = 20;
    Node *head = makeRandomList(n);
    printList(head);
    head = QuickerSort(head);
    printList(head);
}