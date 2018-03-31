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

// A structure to represent a node.
struct Node
{
    double value;
    struct Node* next;
};



