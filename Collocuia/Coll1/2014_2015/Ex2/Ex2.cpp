//author: @kaspiotr (Piotr Kasprzyk)

//Zad.2, kol1, 2014/2015
//Dane są następujące struktury:
//struct Node { Node* next; int val; };
//struct TwoLists { Node* even; Node* odd; };
//Napisać funkcję: TwoLists split(Node* list);
//Funkcja rozdziela listę na dwie: jedną zawierającą liczby parzyste i drugą zawierającą liczby
//nieparzyste. Listy nie zawierają wartowników.

#include <iostream>

using namespace std;

struct Node {
    int val;
    Node *next;
};

struct TwoLists {
    Node *even;
    Node *odd;
};

//funckja do dodawania nowego Node'a do listy na poczatek listy
void addNodeToList(Node *&head, int v) {
    Node *newNode = new Node;
    newNode->val = v;
    newNode->next = head;
    head = newNode;
}

//funkcja do tworzenia losowej listy jednokierunkowej o podanej dlugosci
Node *makeRandomList(int n) {
    srand(time(NULL));
    Node *head = NULL;
    for (int i = 0; i < n; i++) addNodeToList(head, rand() % 10);
    return head;
}

//funckja pomocnicza do wypisywania listy jednokierunkowej
void printList(Node *first) {
    while (first != NULL) {
        cout << first->val << "\t";
        first = first->next;
    }
    cout << endl;
}

TwoLists split(Node *list) {
    TwoLists result;
    result.even = NULL;
    result.odd = NULL;

    while (list != NULL) {
        if ((list->val) % 2 == 0) {
            if (result.even == NULL) {
                result.even = list;
                list = list->next;
                result.even->next = NULL;
            } else {
                Node *curr = result.even, *prev = NULL;
                while (curr != NULL) {
                    prev = curr;
                    curr = curr->next;
                }
                prev->next = list;
                list = list->next;
                prev->next->next = NULL;
            }
        } else {
            if (result.odd == NULL) {
                result.odd = list;
                list = list->next;
                result.odd->next = NULL;
            } else {
                Node *curr = result.odd, *prev = NULL;
                while (curr != NULL) {
                    prev = curr;
                    curr = curr->next;
                }
                prev->next = list;
                list = list->next;
                prev->next->next = NULL;
            }
        }
    }

    return result;
}

int main() {

    Node *first = makeRandomList(10);

    printList(first);

    TwoLists twoLists = split(first);

    printList(twoLists.even);
    printList(twoLists.odd);

    return 0;
}