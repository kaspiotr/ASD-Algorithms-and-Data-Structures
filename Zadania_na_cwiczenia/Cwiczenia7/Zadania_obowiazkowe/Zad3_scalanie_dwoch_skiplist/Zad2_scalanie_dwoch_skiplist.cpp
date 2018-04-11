//
// Created by kaspiotr on 4/10/18.
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

//scalenie dwóch SkipList
SkipList merge(SkipList A, SkipList B)
{
    SkipList S = create();
    SLNode * tmp = S.first;


    while (A.first->next[0]->value < max_ && A.first->next[0]!=NULL && A.first->next[0]!=NULL&& B.first->next[0]->value < max_)
    {
        int valA = A.first->next[0]->value;
        int valB = B.first->next[0]->value;
        cout<<valB<<endl;
        if (valA < valB)
        {
            cout<<"ble"<<endl;
            for (int i = MAX_LEVEL - 1; i >= 0; i--)
            {
                cout<<"ble"<<endl;
                //dodanie elementu
                if (A.first->next[i] != NULL){
                    A.first->next[i] = NULL;
                    tmp->next[i] = A.first->next[i];
                    //cout<<"ble"<<endl;
                    //uaktualnienie wskaźników w listach
                    tmp = tmp->next[i];
                    A.first = A.first->next[i];
                }

                if (A.first->next[i] == NULL) A.first->next[i]=NULL;
                //  cout<<"ble"<<endl;
            }
        }
        else
        {
            //   cout<<"ble"<<endl;

            for (int i = MAX_LEVEL - 1; i >= 0; i--)
            {
                if (B.first->next[i] != NULL){
                    //dodanie elementu
                    B.first->next[i] = NULL;
                    tmp->next[i] = B.first->next[i];

                    //uaktualnienie wskaźników w listach
                    tmp = tmp->next[i];
                    B.first = B.first->next[i];
                }

                if (B.first->next[i] == NULL) B.first->next[i]=NULL;
                //  cout<<"ble"<<endl;

            }
        }
    }

    //return S;
}