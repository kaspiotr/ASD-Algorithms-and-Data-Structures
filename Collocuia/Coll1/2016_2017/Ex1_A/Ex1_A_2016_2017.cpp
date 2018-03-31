//author: @kaspiotr (Piotr Kasprzyk)

//Zad.1 gr. A, kol1, 2016/2017
//Dana jest struktura opisujaca liste jednokierunkowa dla liczb rzeczywistych:
//struct Node{
//    Node* next;
//    double value;
//}
//Prosze zaimplementowac funkcje void Sort( Node* list ), ktora otrzymuje na wejsciu liste
//liczb rzeczywistych (z wartownikiem), wygenerowana zgodnie z rozkladem jednostajnym na
//przedziale [0,10) i sortuje jej zawartosc w kolejnosci niemalejacej. Funkcja powinna byc mozliwie
//jak najszybsza (biorac pod uwage warunki zadania).
//Prosze oszacowac zlozonosc zaimplementowanej funkcji.

#include <iostream>

using namespace std;

struct Node
{
    double value;
    struct Node* next;
};

//funkcja pomocnicza do wyswietlania listy z wartownikiem
void printList(Node *first) {
    first = first->next;
    while (first != NULL) {
        cout << first->value << "\t\t";
        first = first->next;
    }
    cout << endl;
}

//funckja zwracajaca ilosc elementow w liscie jednokierunkowej -przyjmuje na wejsciu liste z wartownikiem
int noOfEls(Node *first) {
    first = first->next;
    int counter=0;
    while(first != NULL) {
        counter++;
        first = first->next;
    }
    return counter;
}

//funkcja pomocnicza sortujaca liste z wykorzystaniem algorytmu insertionSort
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

void Sort(Node* &list) {
    int bucketsNo = noOfEls(list); //bucketsNo = ilosci elementow w liscie
    if(bucketsNo < 2) return; //bo lista jednoelementowa jest juz posortowana
    Node **buckets = new Node* [bucketsNo];

    for(int i=0; i<bucketsNo; i++) buckets[i]=NULL;

    //rozdzielamy liste wejsciowa do kubelkow
    Node *curr = list->next;
    while(curr != NULL) {
        int idx = (int)((curr->value)/10.0*bucketsNo); //idx -numer kubelka, do ktorego przydzielamy element
        if(idx == bucketsNo) idx--; //dla wartosci bardzo bliskich 10 idx==bucketsNo i wtedy trzeba zrobic tak
        if(buckets[idx] == NULL) {
            buckets[idx] = curr;
            curr = curr->next;
            buckets[idx]->next = NULL;
        } else {
            Node* tmp = buckets[idx];
            buckets[idx] = curr;
            curr = curr->next;
            buckets[idx]->next = tmp;
        }
    }

    //sortujemy kazdy z kubelkow insertionSort'em
    for(int i=0; i<bucketsNo; i++) {
        insertionSort(buckets[i]);
    }

    //laczymy kubelki z posortowanymi listami
    Node *last = NULL;
    bool firstFound = false;
    for(int i=0; i<bucketsNo; i++) {
        if(buckets[i] != NULL) {
            if(!firstFound) {
                firstFound = true;
                list->next = buckets[i];
            } else {
                last->next = buckets[i];
            }
            Node *prev = NULL, *curr = buckets[i];
            while(curr != NULL) {
                prev = curr;
                curr = curr->next;
            }
            last = prev;
        }
    }

    delete [] buckets;
}

int main() {

    //implementation of exemplary linked list with sentry
    Node *sentry = new Node; //wartownik

    Node *first = new Node;
    sentry->next = first;
    first->value = 3.2;

    Node *p1 = new Node;
    first->next = p1;
    p1->value = 1.4;

    Node *p2 = new Node;
    p1->next = p2;
    p2->value = 2.8;

    p1 = new Node;
    p2->next = p1;
    p1->value = 3.1;

    p2 = new Node;
    p1->next = p2;
    p2->value = 2.4;

    p1 = new Node;
    p2->next = p1;
    p1->value = 3.15;

    p2 = new Node;
    p1->next = p2;
    p2->value = 8.7;

    p1 = new Node;
    p2->next = p1;
    p1->value = 9.9;

    p2 = new Node;
    p1->next = p2;
    p2->value = 7.1;

    p1 = new Node;
    p2->next = p1;
    p1->value = 5.5;

    p2 = new Node;
    p1->next = p2;
    p2->value = 4.1;

    p1 = new Node;
    p2->next = p1;
    p1->value = 4.6;

    p2 = new Node;
    p1->next = p2;
    p2->value = 6.8;

    p1 = new Node;
    p2->next = p1;
    p1->value = 7.6;

    p2 = new Node;
    p1->next = p2;
    p2->value = 9.2;

    p1 = new Node;
    p2->next = p1;
    p1->value = 2.3;

    p1->next = NULL;

    printList(sentry);

    Sort(sentry);

    printList(sentry);

    return 0;
}