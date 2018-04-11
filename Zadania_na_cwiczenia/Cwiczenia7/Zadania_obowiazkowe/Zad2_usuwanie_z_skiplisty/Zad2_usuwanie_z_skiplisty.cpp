//
// Created by Karolina on 11.04.2018.
//
#include <iostream>
#include <cstdlib>
using namespace std;

struct SLNode
{
    int value;
    int level;
    SLNode ** next;
};

struct SkipList
{
    SLNode * first;
    SLNode * last;
};

int getlevel()
{
    int lvl = 1;
    while (lvl < MAX_LEVEL && rand() < 0.5) lvl++;
    return lvl;
}
//usuwanie inta
void remove(SkipList S, int key)
{
    SLNode * tmp = S.first;
    SLNode * del;

    for (int i = MAX_LEVEL - 1; i >= 0; i--)
    {
        //szukanie miejsca węzła
        while (tmp->next[i] != NULL && tmp->next[i]->value < key)
            tmp = tmp->next[i];

        //wstawienie nowego węzła
        if(tmp->next[i]->value == key)
        {
            del = tmp->next[i];
            tmp->next[i] = del->next[i];
        }
    }

    if (tmp->next[0]->value != key) return;
    delete del->next[0];


}
