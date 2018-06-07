#include <iostream>
#include <queue>

using namespace std;

struct Graph {
    bool **E;
    int size;
};

struct PathTree {
    int parent;
    int d;
};

PathTree *BFS(Graph *G, int s) {
    queue<int> Q;
    PathTree *P = new PathTree[G->size];

    for (int v = 0; v < G->size; v++) {
        P[v].d = -1;
        P[v].parent = -1;
    }
    P[s].d = 0;
    Q.push(s);

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        for (int v = 0; v < G->size; v++) {
            if (G->E[u][v] && P[v].d < 0) {
                P[v].d = P[u].d + 1;
                P[v].parent = u;
                Q.push(v);
            }
        }
    }

    return P;
}

// funkcja wypisujaca sciezka z konkretnego wierzcholka do wierzcholka v
void PrintPath(PathTree *P, int v) {
    if (P[v].parent != -1) {
        PrintPath(P, P[v].parent);
        cout << v;
    } else {
        cout << v;
    }
}

int main() {

    Graph *G = new Graph;
    G->size = 7;
    G->E = new bool *[G->size];

    // inicjalizacja grafu
    for (int i = 0; i < G->size; i++) {
        G->E[i] = new bool[G->size];
        for (int j = 0; j < G->size; j++) {
            G->E[i][j] = false;
        }
    }

    // dodanie krawedzi dla danego grafu
    G[0][1] = true;
    G[0][3] = true;
    G[1][2] = true;
    G[2][5] = true;
    G[3][2] = true;
    G[3][4] = true;
    G[5][3] = true;

    PathTree *P = BFS(G, 0);

    PrintPath(P, 5);

    return 0;
}