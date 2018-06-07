#include "queue.h"
#include <stdio.h>
#include <limits.h>

typedef struct Graph {
    bool **data;
    int size;
} Graph;

typedef struct PathTree {
    int parent;
    int distance;
    int time;
    bool visited;
} PathTree;

PathTree *BFS(Graph *graph, int s) {
    Queue queue; init(&queue, graph->size);
    PathTree *path_tree = malloc(graph->size * sizeof(PathTree));

    for (int i = 0; i < graph->size; i++) {
        path_tree[i].distance = path_tree[i].parent = -1;
    }

    path_tree[s].distance = 0;

    put(&queue, s);

    while (!empty(&queue)) {
        int u = get(&queue);

        for (int v = 0; v < graph->size; v++) {
            if (graph->data[u][v] && path_tree[v].distance < 0) {
                path_tree[v].parent = u;
                path_tree[v].distance = path_tree[u].distance + 1;
                put(&queue, v);
            }
        }
    }

    free(queue.data);
    return path_tree;
}

void DFS_visit(Graph *graph, int u, int *time, PathTree *path_tree) {
    path_tree[u].visited = true;

    *time += 1;

    printf("%d visited\n", u);

    for (int v = 0; v < graph->size; v++) {
        if (graph->data[u][v] && !path_tree[v].visited) {
            path_tree[v].parent = u;
            DFS_visit(graph, v, time, path_tree);
//            **time += 1;
        }
    }

    *time += 1;

    printf("%d exited, time = %d\n", u, *time);
    path_tree[u].time = *time;

}

PathTree *DFS(Graph *graph) {
    PathTree *path_tree = malloc(graph->size * sizeof(PathTree));

    for (int i = 0; i < graph->size; i++) {
        path_tree[i].time = INT_MIN;
        path_tree[i].visited = false;
    }

    int time = 0;

    for (int u = 0; u < graph->size; u++) {
        if (!path_tree[u].visited) DFS_visit(graph, u, &time, path_tree);
    }

    return path_tree;
}

void graph_print(Graph *graph) {
    printf(" ");
    for (int i = 0; i < graph->size; i++) printf("%d", i);
    printf("\n");

    for (int u = 0; u < graph->size; u++) {
        printf("%d", u);
        for (int v = 0; v < graph->size; v++) {
            if (graph->data[u][v]) printf("1");
            else printf(" ");
        }
        printf("\n");
    }
}

Graph *graph_create(int n, bool insert) {
    Graph *graph = malloc(sizeof(Graph));

    graph->size = n;
    graph->data = malloc(graph->size * sizeof(bool *));

    for (int i = 0; i < graph->size; i++) {
        graph->data[i] = malloc(graph->size * sizeof(bool));
    }

//    if (!insert) return graph;

    for (int i = 0; i < graph->size; i++) {
        for (int j = 0; j < graph->size; j++) {
            if (i != j && insert) graph->data[i][j] = rand() % 2 == 1 ? true : false;
            else graph->data[i][j] = false;
        }
    }

    return graph;
}

void graph_add_edge(Graph *graph, int u, int v) {
    graph->data[u][v] = 1;
}

void graph_free(Graph *graph) {
    for (int i = 0; i < graph->size; i++) free(graph->data[i]);
    free(graph->data);
    free(graph);
}

int main() {
    int n = 4;

    Graph *graph = graph_create(n, false);
//    graph.size = n;
//    bool **arr = malloc(n * sizeof())
//    bool arr[n] = {
//            {false, true, false, false},
//            {false, false, true, true},
//            {false, false, false, false},
//            {false, false, true, false}
//    };
    graph_add_edge(graph, 0, 1);
    graph_add_edge(graph, 1, 2);
    graph_add_edge(graph, 1, 3);
    graph_add_edge(graph, 3, 2);

    graph_print(graph);

    printf("\n");

//    PathTree *path_tree = BFS(graph, 0);
    PathTree *path_tree = DFS(graph);
    for (int i = 0; i < graph->size; i++) {
//        printf("%d: p=%d, d=%d\n", i, path_tree[i].parent, path_tree[i].distance);
        printf("%d: p=%d, t=%d\n", i, path_tree[i].parent, path_tree[i].time);
    }
    free(path_tree);

    graph_free(graph);

    return 0;
}