#include <iostream>

using namespace std;

struct Graph {
    bool **E;
    int size;
};

struct PathTree {
    int parent;
    int d; //d -distance
    int visitTime; //czas odwiedzenia
    int processTime; //czas przetworzenia
    bool visited;
};

void DFSVisit(Graph *G, int v, int &time, PathTree *P) {
    P[v].visited = true;
    P[v].visitTime = time;
    time += 1;

    for(int w=0; w<G->size; w++) {
        if(G->E[v][w] && !P[w].visited) {
            P[w].parent = v;
            P[w].d = P[v].d + 1;
            DFSVisit(G, w, time, P);
        }
    }
    P[v].processTime = time;
    time += 1;
}

PathTree* DFS(Graph *G) {

    PathTree *P = new PathTree [G->size];

    for(int v=0; v<G->size; v++) {
        P[v].parent = INT32_MIN;
        P[v].d = INT32_MIN;
        P[v].processTime = INT32_MIN;
        P[v].visitTime = INT32_MIN;
        P[v].visited = false;
    }

    int time = 0;

    for(int v=0; v<G->size; v++) {
        if(!P[v].visited) {
            P[v].parent = -1;
            P[v].d = 0;
            DFSVisit(G, v, time, P);
        }
    }

    return P;
}

int main() {

    Graph *G = new Graph;
    G->size = 6;
    G->E = new bool* [G->size];
    for(int v=0; v<G->size; v++) {
        G->E[v] = new bool [G->size];
        for(int w=0; w<G->size; w++) {
            G->E[v][w] = false;
        }
    }

    G->E[0][1] = true;
    G->E[1][4] = true;
    G->E[4][0] = true;
    G->E[4][3] = true;
    G->E[4][5] = true;
    G->E[5][1] = true;

    PathTree *P = DFS(G);

    for(int i=0; i<G->size; i++) {
        cout<<i<<") Parent= "<<P[i].parent<<", d= "<<P[i].d<<", visited= "<<P[i].visited<<", visitTime= "<<P[i].visitTime<<", processTime="<<P[i].processTime;
        cout<<endl;
    }

    return 0;
}