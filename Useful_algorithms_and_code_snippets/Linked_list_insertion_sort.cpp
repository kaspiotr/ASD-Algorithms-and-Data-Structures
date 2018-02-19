//author: @kaspiotr (Piotr Kasprzyk)

//Implementation of insertion sort algorithm on a linked list

#include <iostream>

using namespace std;

struct Node {
    int v;
    Node *next;
};

void printList(Node *first) {
    while(first != NULL) {
        cout<<first->v<<"\t";
        first = first->next;
    }
    cout<<endl;
}

void insertionSort(Node* &first) {

    if(first == NULL || first->next == NULL) return;

    Node *last = first, *curr = first->next;
    Node *p, *prev;

    while(curr != NULL) {
        p = first, prev = NULL;
        while(p != NULL && p != curr && p->v < curr->v) {
            prev = p;
            p = p->next;
        }

        if(p == curr) {
            last = curr;
        } else if(p == first) {
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

    insertionSort(first);

    printList(first);

    return 0;
}