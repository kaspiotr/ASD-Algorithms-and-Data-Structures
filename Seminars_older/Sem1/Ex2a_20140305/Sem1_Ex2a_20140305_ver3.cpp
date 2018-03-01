//author: @kaspiotr (Piotr Kasprzyk)

/*
Zad.2c, Cw.1, ASD, 5.03.14
Prosze zaimplementowac znajdowanie i usuwanie elementu najwiekszego z nieposortowanej listy jednokierunkowej liczb
bez wartownika
 */

#include <iostream>

using namespace std;

struct Node {
    int v;
    Node *next;
};

void printList(Node *first) {
    while (first != NULL) {
        cout << first->v << "\t";
        first = first->next;
    }
    cout << endl;
}

Node *findMax(Node* &first, Node* &prevMax) {
    int maxVal = first->v;
    Node *curr = first->next, *prev = NULL;
    Node *max = first;
    while (curr != NULL) {
        if (maxVal < curr->v) {
            maxVal = curr->v;
            prevMax = prev;
            max = curr;
        }
        prev = curr;
        curr = curr->next;
    }

    return max;
}

void deleteMax(Node* &first) {
    if (first == NULL) return;
    if (first->next == NULL) {
        Node *tmp = first;
        first = NULL;
        delete tmp;
        return;
    }

    Node *prevMax = NULL, *max = first;
    max = findMax(first, prevMax);
    prevMax->next = max->next;
    delete max;
}

int main() {

    //implementation of exemplary linked list
    Node *first = new Node;
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

    printList(first);

    deleteMax(first);

    printList(first);

    return 0;
}