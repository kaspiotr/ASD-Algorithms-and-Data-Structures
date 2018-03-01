//author: @kaspiotr (Piotr Kasprzyk)

/*
Zad.2a Cw.1 5.03.2014
Prosze zaimplementowac znajdowanie i usuwanie elementu największego z listy jednokierunkowej z wartownikiem
 */

#include <iostream>

using namespace std;

struct Node {
    int v;
    Node *next;
};

//funckja przyjmujaca wkaznik na wartownika i wypisujaca zawartosc listy
void printList(Node *first) {
    first = first->next;
    while (first != NULL) {
        cout << first->v << "\t";
        first = first->next;
    }
    cout << endl;
}

//funkcja zwracajaca wartosc najwiekszego elementu listy; przyjmuje wskaznik na wartownika
int maxEl(Node *first) {
    first = first->next;
    int maxEl = first->v;
    while(first != NULL) {
        if(maxEl < first->v) {
            maxEl = first->v;
        }
        first = first->next;
    }

    return maxEl;
}

//funckja przyjmuje wskaznik na wartownika listy
void delMaxEl(Node* &first) {
    if(first->next == NULL) return;
    int maxVal = maxEl(first);
    Node *prev = first, *curr = first->next;
    while(curr != NULL) {
        if(curr->v == maxVal) {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
}

int main() {

    //implementation of exemplary linked list
    Node *w = new Node;

    Node *first = new Node;
    w->next = first;
    first->v = 5;

    Node *p1 = new Node;
    first->next = p1;
    p1->v = 2;

    Node *p2 = new Node;
    p1->next = p2;
    p2->v = 4;

    p1 = new Node;
    p2->next = p1;
    p1->v = 6;

    p2 = new Node;
    p1->next = p2;
    p2->v = 1;

    p1 = new Node;
    p2->next = p1;
    p1->v = 3;

    p1->next = NULL;

    printList(w);

    delMaxEl(w);

    printList(w);

    return 0;
}