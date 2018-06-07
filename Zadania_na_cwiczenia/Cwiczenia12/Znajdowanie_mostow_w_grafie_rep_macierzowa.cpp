#include <iostream>

using namespace std;

struct Graph {
    bool **E;
    int size;
};

struct PathTree {
    int parent;
    int low;
    int timeVisit;
    int timeExit;
    bool visited;
    bool isBridge;
};



// funkcja wypisujaca sciezka z konkretnego wierzcholka do wierzcholka v
void PrintPath(PathTree *P, int v) {
    if (P[v].parent != -1) {
        PrintPath(P, P[v].parent);
        cout << v << " ";
    } else {
        cout << v << " ";
    }
}

void printGraph(Graph *G) {
    printf("  ");
    for (int i = 0; i < G->size; i++) printf("%d", i);
    printf("\n");

    for (int u = 0; u < G->size; u++) {
        printf("%d ", u);
        for (int v = 0; v < G->size; v++) {
            if (G->E[u][v]) printf("1");
            else printf(" ");
        }
        printf("\n");
    }
}

int low(Graph *G, PathTree *P, int v) {
    int min = P[v].timeVisit;
    for(int u=0; u<G->size; u++) {
        if(G->E[v][u] && P[v].parent != u && P[u].visited){ //jesli jest krawedz wsteczna z v do u
            if(min > P[u].timeVisit) {
                min = P[u].timeVisit;
            }
        }
    }

    for(int w=0; w<G->size; w++) {
        if(P[w].parent == v){
            if(min > P[w].low){
                min = P[w].low;
            }
        }
    }

    return min;
}

void DFSVisit(Graph *G, int u, int &timeVisit, int &timeExit, PathTree *P) {
    P[u].visited = true;


    timeVisit += 1;
    timeExit += 1;
    P[u].timeVisit = timeVisit; //zapisujemy czas odwiedzenia

    printf("%d visited\n", u);

    for (int v = 0; v < G->size; v++) {
        if (G->E[u][v] && !P[v].visited) {
            P[v].parent = u;
            DFSVisit(G, v, timeVisit, timeExit, P);
//            **time += 1;
        }
    }

    timeExit += 1;

    printf("%d exited, time = %d\n", u, timeExit);
    P[u].timeExit = timeExit; //nie zapisujemy czasu przetworzenia
    P[u].low = low(G, P, u);

}



PathTree *DFS(Graph *G) {
    PathTree *P = new PathTree[G->size];

    for (int i = 0; i < G->size; i++) {
        P[i].parent = -1;
        P[i].timeVisit = INT32_MIN;
        P[i].timeExit = INT32_MIN;
        P[i].visited = false;
        P[i].isBridge = false;
        P[i].low = INT32_MAX;
    }

    int timeVisit = 0;
    int timeExit = 0;

    for (int u = 0; u < G->size; u++) {
        if (!P[u].visited) DFSVisit(G, u, timeVisit, timeExit, P);
    }

    return P;
}

//algorytm znajdujacy mosty w grafie
PathTree* findBridges(Graph *G) {
    //przechodzimy graf DFSem z zapamietywaniem czasow odwiedzenia
    PathTree *P = DFS(G);

    //sprawdzamy czy dany wiercholek jest wierzcholkiem koncowym mostu
    for(int v=0; v<G->size; v++) {
        if(P[v].timeVisit == P[v].low && P[v].parent != -1) {
            P[v].isBridge = true;
        }
    }

    return P;
}

int main() {

    //implementacja pierwszego grafu
    Graph *G1 = new Graph;
    G1->size = 8;
    G1->E = new bool* [G1->size];

    // inicjalizacja grafu
    for (int i = 0; i < G1->size; i++) {
        G1->E[i] = new bool[G1->size];
        for (int j = 0; j < G1->size; j++) {
            G1->E[i][j] = false;
        }
    }

    // dodanie krawedzi do pierwszego grafu
    G1->E[0][1] = true;
    G1->E[0][5] = true;
    G1->E[1][0] = true;
    G1->E[1][2] = true;
    G1->E[2][1] = true;
    G1->E[2][3] = true;
    G1->E[2][5] = true;
    G1->E[3][2] = true;
    G1->E[3][4] = true;
    G1->E[3][6] = true;
    G1->E[4][3] = true;
    G1->E[4][6] = true;
    G1->E[5][0] = true;
    G1->E[5][2] = true;
    G1->E[5][7] = true;
    G1->E[6][3] = true;
    G1->E[6][4] = true;
    G1->E[7][5] = true;


    //implementacja drugiego grafu
    Graph *G2 = new Graph;
    G2->size = 7;
    G2->E = new bool* [G2->size];

    // inicjalizacja grafu
    for (int i = 0; i < G2->size; i++) {
        G2->E[i] = new bool[G2->size];
        for (int j = 0; j < G2->size; j++) {
            G2->E[i][j] = false;
        }
    }

    // dodanie krawedzi do drugiego grafu
    G2->E[0][1] = true;
    G2->E[0][2] = true;
    G2->E[0][3] = true;
    G2->E[1][0] = true;
    G2->E[1][4] = true;
    G2->E[1][5] = true;
    G2->E[2][0] = true;
    G2->E[2][3] = true;
    G2->E[2][6] = true;
    G2->E[3][0] = true;
    G2->E[3][2] = true;
    G2->E[3][6] = true;
    G2->E[4][1] = true;
    G2->E[4][5] = true;
    G2->E[5][1] = true;
    G2->E[5][4] = true;
    G2->E[6][2] = true;
    G2->E[6][3] = true;

    printGraph(G1);
    printGraph(G2);

    PathTree *P1 = findBridges(G1);

    for(int i=0; i<G1->size; i++) {
        cout<<i<<") "<<"time of visit: "<<P1[i].timeVisit<<"\t"<<"time of exit: "<<P1[i].timeExit<<"\t"<<"parent: "<<P1[i].parent<<"\t"<<"low: "<<P1[i].low<<"\t"<<"isBridge: "<<P1[i].isBridge<<endl;
    }

    PathTree *P2 = findBridges(G2);

    for(int i=0; i<G2->size; i++) {
        cout<<i<<") "<<"time of visit: "<<P2[i].timeVisit<<"\t"<<"time of exit: "<<P2[i].timeExit<<"\t"<<"parent: "<<P2[i].parent<<"\t"<<"low: "<<P2[i].low<<"\t"<<"isBridge: "<<P2[i].isBridge<<endl;
    }

    return 0;
}