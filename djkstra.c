#include <stdio.h>

#define MAX_NODES 100
#define INF 9999

void addEdge_dir(int u, int v, int weight, int adjMatrix[MAX_NODES][MAX_NODES])
{
    adjMatrix[u][v] = weight;
}

void addEdge_undir(int u, int v, int weight, int adjMatrix[MAX_NODES][MAX_NODES])
{
    adjMatrix[u][v] = weight;
    adjMatrix[v][u] = weight;
}

void displayMatrix(int nodes, int adjMatrix[MAX_NODES][MAX_NODES])
{
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < nodes; i++)
    {
        for (int j = 0; j < nodes; j++)
            if (adjMatrix[i][j] == 0)
                printf("%3c ", 236);
            else
                printf("%3d ", adjMatrix[i][j]);
        printf("\n");
    }
}

int minDistance(int dist[], int sptSet[], int nodes)
{
    int min = INF, min_index;

    for (int v = 0; v < nodes; v++)
        if (!sptSet[v] && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void dijkstra(int nodes, int adjMatrix[MAX_NODES][MAX_NODES], int src)
{
    int dist[MAX_NODES], sptSet[MAX_NODES];

    for (int i = 0; i < nodes; i++)
        dist[i] = INF, sptSet[i] = 0;

    dist[src] = 0;

    for (int count = 0; count < nodes - 1; count++)
    {
        int u = minDistance(dist, sptSet, nodes);

        sptSet[u] = 1;

        for (int v = 0; v < nodes; v++)
            if (!sptSet[v] && adjMatrix[u][v] && dist[u] != INF && dist[u] + adjMatrix[u][v] < dist[v])
                dist[v] = dist[u] + adjMatrix[u][v];
    }

    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < nodes; i++)
        printf("%d \t\t %d\n", i + 1, dist[i]);
}

int main()
{
    int nodes, edges, weight, u, v, ch;
    int adjMatrix[MAX_NODES][MAX_NODES] = {0};

    printf("Enter number of nodes in the graph: ");
    scanf("%d", &nodes);

    printf("Enter number of edges in the graph: ");
    scanf("%d", &edges);

    printf("1. Directed Graph\n2. Un-directed Graph\nEnter your choice: ");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1:
            printf("Enter the edges (format: from_node to_node weight) (node value starts from 1): \n"); //node value starts from 1
            fflush(stdin);
            for (int i = 0; i < edges; i++)
            {
                scanf("%d %d %d", &u, &v, &weight);
                addEdge_dir(u - 1, v - 1, weight, adjMatrix);
            }
            break;
        case 2:
            printf("Enter the edges (format: from_node to_node weight) (node value starts from 1): \n"); //node value starts from 1
            fflush(stdin);
            for (int i = 0; i < edges; i++)
            {
                scanf("%d %d %d", &u, &v, &weight);
                addEdge_undir(u - 1, v - 1, weight, adjMatrix);
            }
            break;   
        default:
            printf("Invalid input");
            return 0;
    }

    displayMatrix(nodes, adjMatrix);

    printf("Enter the source vertex: ");
    scanf("%d", &u);

    dijkstra(nodes, adjMatrix, u - 1);

    return 0;
}
