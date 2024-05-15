#include <stdio.h>
#include <stdlib.h>

#define INF 9999
#define MAX_NODES 100

struct Edge {
    int src, dest, weight;
};

void addEdge_dir(int u, int v, int weight, struct Edge edges[], int *E) {
    edges[*E].src = u;
    edges[*E].dest = v;
    edges[*E].weight = weight;
    (*E)++;
}

void addEdge_undir(int u, int v, int weight, struct Edge edges[], int *E) {
    edges[*E].src = u;
    edges[*E].dest = v;
    edges[*E].weight = weight;
    (*E)++;
    
    edges[*E].src = v;  // Adding the reverse edge for undirected graph
    edges[*E].dest = u;
    edges[*E].weight = weight;
    (*E)++;
}

void displayEdges(int E, struct Edge edges[]) {
    int i;
    printf("Edges:\n");
    for (i = 0; i < E; ++i) {
        printf("(%d, %d) weight %d\n", edges[i].src+1, edges[i].dest+1, edges[i].weight);
    }
}

void bellmanFord(int V, int E, struct Edge edges[], int start) {
    int i, j, distance[V], parent[V], u, v, w;
    for (i = 0; i < V; ++i) {
        distance[i] = INF;
        parent[i] = -1; // Initialize parent array to -1
    }
    distance[start] = 0;

    for (i = 1; i < V; ++i) {
        for (j = 0; j < E; ++j) {
            u = edges[j].src;
            v = edges[j].dest;
            w = edges[j].weight;
            if (distance[u] != INF && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
                parent[v] = u; // Update parent vertex
            }
        }
    }

    // Check for negative weight cycles
    for (i = 0; i < E; ++i) {
        u = edges[i].src;
        v = edges[i].dest;
        w = edges[i].weight;
        if (distance[u] != INF && distance[u] + w < distance[v]) {
            printf("Negative weight cycle detected!\n");
            return;
        }
    }

    // Print shortest distances and paths
    printf("Vertex\tDistance from Start\tPath\n");
    for (i = 0; i < V; ++i) {
        printf("%d\t%d\t\t\t", i + 1, distance[i]);
        int current = i;
        while (current != start) {
            printf("%d <- ", current + 1);
            current = parent[current];
        }
        printf("%d\n", start + 1);
    }
}



int main() {
    int V, E, start, ch, src, dest, weight, i;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);

    struct Edge edges[MAX_NODES];
    printf("1. Directed Graph\n2. Un-directed Graph\nEnter your choice: ");
    scanf("%d", &ch);

    int totalEdges = 0;

    switch (ch) {
        case 1:
            printf("Enter the edges (format: source destination weight) (node value strats from 1):\n");
            for (i = 0; i < E; ++i) {
                scanf("%d %d %d", &src, &dest, &weight);
                addEdge_dir(src-1, dest-1, weight, edges, &totalEdges);
            }
            break;
        case 2:
            printf("Enter the edges (format: source destination weight) (node value strats from 1):\n");
            for (i = 0; i < E; ++i) {
                scanf("%d %d %d", &src, &dest, &weight);
                addEdge_undir(src-1, dest-1, weight, edges, &totalEdges);
            }
            break;
        default:
            printf("Invalid choice.\n");
            return 1;
    }

    displayEdges(totalEdges, edges);

    printf("Enter the starting vertex: "); //node value starts from 1
    scanf("%d", &start);

    bellmanFord(V, totalEdges, edges, start-1);

    return 0;
}

/*
Output:
------
Enter number of vertices: 5
Enter number of edges: 8
1. Directed Graph
2. Un-directed Graph
Enter your choice: 1
Enter the edges (format: source destination weight) (node value strats from 1):
1 2 10
2 4 1
1 3 5
3 2 3
3 4 9
3 5 2
5 1 2
5 4 6
Edges:
(1, 2) weight 10
(2, 4) weight 1
(1, 3) weight 5
(3, 2) weight 3
(3, 4) weight 9
(3, 5) weight 2
(5, 1) weight 2
(5, 4) weight 6
Enter the starting vertex: 1
Vertex  Distance from Start     Path
1       0                       1
2       8                       2 <- 3 <- 1
3       5                       3 <- 1
4       9                       4 <- 2 <- 3 <- 1
5       7                       5 <- 3 <- 1
*/