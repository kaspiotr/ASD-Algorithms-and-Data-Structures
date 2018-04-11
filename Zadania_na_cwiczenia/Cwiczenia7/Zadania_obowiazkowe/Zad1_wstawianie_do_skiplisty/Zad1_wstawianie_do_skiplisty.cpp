//
// Created by kaspiotr on 4/10/18.
//

//wstawianie so skiplisty

#include <iostream>
#include <limits.h>
using namespace std;

//struktura opisujaca node'a, z ktorych sklada sie skiplista
struct SLNode {
    int val;
    SLNode **next;
};

//struktura opisujaca skipliste
struct SkipList {
    SLNode *first; //wskaznik na wartownika na poczatku skiplisty
    SLNode *last; //wskaznik na wartownika na koncu skiplisty
    int maxLevel; //pole okreslajace maksymalna mozliwa ilosc poziomow, jaka moze miec node w skipliscie
                  //(w praktyce maksymalny poziom dla node w skipliscie, ktory nie jest wartownikiem to maxLevel-1)
};

//funckja pomocnicza wypisujaca zwartosc skiplisty
void printSkipList(SkipList *sList) {
    SLNode *w = sList->first->next[0];
    while(w->val != INT_MAX) {
        w = w->next[0];
        if(w->val != INT_MAX) cout<<w->val<<"\t";
    }
    cout<<endl;
}

//funckja, ktora w sposob losowy okresla ile wskaznikow ma miec wstawiany do skiplisty nowy node
int level(int maxLevel) {
    int lvl=1;
    srand(time(NULL));
    while(rand() < (RAND_MAX/2)) lvl++;

    return (lvl < maxLevel) ? lvl : maxLevel;
}

//funkcja tworzaca nowy SLNode na podstawie podanej wartosci val i poziomu level jaki ma on miec
SLNode *createNew(int val, int level) {
    SLNode *newSLNode = new SLNode;
    newSLNode->val = val;
    newSLNode->next = new SLNode* [level];

    return newSLNode;
}

//funckja wstawiajaca SLNode'a do skiplisty o podanej wartosic val
void insert(SkipList* &sList, int key) {
    SLNode * w = sList->first; //roboczy wskaznik, ktorym bedziemy przechodzic skipliste
    int h = level(sList->maxLevel); //losujemy wysokosc (romiar tablicy wskaznikow) dla dodawanego SLNode'a
    SLNode *newSLNode = new SLNode;
    newSLNode->val = key;
    newSLNode->next = new SLNode* [h];

    for (int i = sList->maxLevel - 1; i >= 0; i--) {
        while (key > w->next[i]->val)
            w = w->next[i];
        if (i < h) {
            newSLNode->next[i] = w->next[i];
            w->next[i] = newSLNode;
        }
    }

}

//funkcja pomocnicza do tworzenia nowej, losowej skiplisty
SkipList* createRandSkipList(int noOfEls, int maxLevel) {
    srand(time(NULL));
    //tworzenie strucktury SkipListy
    SkipList *sList = new SkipList;
    sList->first = new SLNode;
    sList->last = new SLNode;
    sList->maxLevel = maxLevel;

    //tworzenie wartownikow poczatkowego i koncowego
    sList->first->val = INT_MIN;
    sList->first->next = new SLNode* [maxLevel];
    sList->last->val = INT_MAX;
    sList->last->next = new SLNode *[maxLevel];

    //laczenie wskaznikow wartownika poczatkowego ze wskaznikami wartownika koncowego
    for(int i=0; i<maxLevel; i++) {
        sList->first->next[i] = sList->last;
    }

    //tworzenie losowej skiplisty z wykorzystaniem funkcji insert
    int currMaxVal = INT_MIN;
    int currVal;
    int min = 1, max = 100;
    for(int i=0; i<noOfEls; i++) {

        currVal = min + (rand() * (int)(max - min) / RAND_MAX);
        while(currVal < currMaxVal) {
            currVal = min + (rand() * (int)(max - min) / RAND_MAX);
        }
        currMaxVal = currVal;
        insert(sList, currVal);
    }

    return sList;
}

int main() {



    cout<<INT_MIN<<endl;
    cout<<INT_MAX<<endl;
    cout<<RAND_MAX<<endl;

    SkipList *skipList = createRandSkipList(3, 6);

    printSkipList(skipList);

    insert(skipList, 7);

    printSkipList(skipList);

    return 0;
}