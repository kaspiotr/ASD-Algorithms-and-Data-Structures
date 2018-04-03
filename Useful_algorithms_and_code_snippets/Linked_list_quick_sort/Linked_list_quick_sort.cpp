//author: @kaspiotr (Piotr Kasprzyk)

//Implementation of quick sort algorithm on linked list

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

void addNodeToList(Node *&head, int v) {
    Node *newNode = new Node;
    newNode->v = v;
    newNode->next = head;
    head = newNode;
}

Node *makeRandomList(int n) {
    srand(time(NULL));
    Node *head = NULL;
    for (int i = 0; i < n; i++) addNodeToList(head, rand() % 10);
    return head;
}

Node *getTail(Node *head) {
    while (head != NULL && head->next != NULL) {
        head = head->next;
    }
    return head;
}

Node *Partition(Node *&head, Node *&end) {
    Node *pivot = end;
    Node *curr = head, *prev = NULL;
    Node *tail = end;

    while (curr != pivot) {
        if (curr->v < pivot->v) {
            prev = curr;
            curr = curr->next;
        } else {
            if (head == curr) {
                head = head->next;
            }
            if (prev != NULL) {
                prev->next = curr->next;
            }
            Node *tmp = curr->next;
            curr->next = NULL;
            tail->next = curr;
            tail = curr;
            curr = tmp;
        }
    }
    end = tail;
    return pivot;
}

Node *QuickSort(Node *head, Node *end) {

    if (head == NULL || head == end) return head;

    Node *pivot = Partition(head, end);
    if (head != pivot) {
        Node *tmp = head;
        while (tmp->next != pivot) {
            tmp = tmp->next;
        }
        tmp->next = NULL;
        head = QuickSort(head, tmp);

        tmp = getTail(head);
        tmp->next = pivot;
    }
    pivot->next = QuickSort(pivot->next, end);
    return head;
}

void listSort(Node *&head) {
    head = QuickSort(head, getTail(head));
    return;
}

int main() {

    //implementation of exemplary linked list
//    Node *first = new Node;
//    first->v = 9;
//
//    Node *p1 = new Node;
//    first->next = p1;
//    p1->v = 2;
//
//    Node *p2 = new Node;
//    p1->next = p2;
//    p2->v = 3;
//
//    p1 = new Node;
//    p2->next = p1;
//    p1->v = 6;
//
//    p2 = new Node;
//    p1->next = p2;
//    p2->v = 5;
//
//    p1 = new Node;
//    p2->next = p1;
//    p1->v = 3;
//
//    p2 = new Node;
//    p1->next = p2;
//    p2->v = 10;
//
//    p1 = new Node;
//    p2->next = p1;
//    p1->v = 1;
//
//    p2 = new Node;
//    p1->next = p2;
//    p2->v = 7;
//
//    p2->next = NULL;

    Node *first = makeRandomList(15);
    printList(first);
    //Node *end = getTail(first);
    //cout<<"pivot->v = "<<(Partition(first, end))->v<<endl;
    first = QuickSort(first, getTail(first));

    printList(first);

    return 0;
}
