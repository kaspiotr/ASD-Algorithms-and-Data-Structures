//author: @kaspiotr (Piotr Kasprzyk)

/*
Zad.5 Ćw.1, 1.03.17
Zaimplementowac funkcje odwracajaca liste jednokierunkowa
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

Node *reverse(Node *head) {
    Node *rhead = NULL;
    while(head != NULL) {
        Node *n = head;
        head = head->next;
        n->next = rhead;
        rhead = n;
    }

    return rhead;
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

    Node *rev = reverse(first);

    printList(rev);

    return 0;
}