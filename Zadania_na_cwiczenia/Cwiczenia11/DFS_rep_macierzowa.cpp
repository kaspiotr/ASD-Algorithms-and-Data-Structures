#include <iostream>

using namespace std;

struct Vertex {
    bool visited;
    int time;
    int parent;
};

struct Graph {
    bool **E;
    int size;
};

void DFSVisit(Graph *G, Vertex *verts, int v, int &time) {
    cout<<v<<" ";
    verts[v].visited = true;
    time += 1;

    for(int w=0; w < G->size; w++) {
        if(G->E[v][w] && !verts[w].visited) {
            verts[w].parent = v;
            DFSVisit(G, verts, w, time);
        }
    }
    verts[v].time = time;
}

void DFS(Graph *G, Vertex *verts) {
    int time = 0;
    for(int v=0; v<G->size; v++) {
        if(!verts[v].visited)
            DFSVisit(G, verts, v, time);
    }
}

int main() {

    Graph *G = new Graph;
    G->size = 6;
    G->E = new bool* [G->size];

    // inicjalizacja grafu
    for (int i = 0; i < G->size; i++) {
        G->E[i] = new bool[G->size];
        for (int j = 0; j < G->size; j++) {
            G->E[i][j] = false;
        }
    }

    // dodanie krawedzi dla danego grafu
    G->E[0][1] = true;
    G->E[0][3] = true;
    G->E[1][2] = true;
    G->E[2][5] = true;
    G->E[3][2] = true;
    G->E[3][4] = true;
    G->E[5][3] = true;

    Vertex *verts = new Vertex [G->size];

    for(int i=0; i<G->size; i++) {
        verts[i].parent = -1;
        verts[i].time = INT32_MIN;
        verts[i].visited = false;
    }

    DFS(G, verts);

    for(int i=0; i<G->size; i++) {
        cout<<i<<") ";
        cout<<"parent: "<<verts[i].parent<<"\t";
        cout<<"time: "<<verts[i].time<<"\t";
        cout<<"visited: "<<verts[i].visited<<"\t";
        cout<<endl;
    }

    return 0;
}
