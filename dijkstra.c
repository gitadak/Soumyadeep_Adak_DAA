//Single source shortest path Dijkstra's algorithm 
//For directed and un-directed graph

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
    int i,j;
    printf("Adjacency Matrix:\n");
    for (i = 0; i < nodes; i++)
    {
        for (j = 0; j < nodes; j++)
        {
            if(i==j)
            {
                printf("%3d ",0);
                continue;
            }
            if(adjMatrix[i][j]==INF)
                printf("%3c ",236);
            else
                printf("%3d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int minDistance(int dist[MAX_NODES], int sptSet[MAX_NODES], int nodes)
{
    int min = INF, min_index,v;

    for (v = 0; v < nodes; v++)
        if (!sptSet[v] && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printPath(int parent[MAX_NODES], int j, int src)
{
    if (parent[j] == -1)
    {
        printf("%d", src + 1);
        return;
    }

    printPath(parent, parent[j], src);
    printf(" -> %d", j + 1);
}

void dijkstra(int nodes, int adjMatrix[MAX_NODES][MAX_NODES], int src)
{
    int dist[MAX_NODES], sptSet[MAX_NODES], parent[MAX_NODES],i,count,u,v;

    for (i = 0; i < nodes; i++)
        dist[i] = INF, sptSet[i] = 0, parent[i] = -1;

    dist[src] = 0;

    for (count = 0; count < nodes - 1; count++)
    {
        u = minDistance(dist, sptSet, nodes);

        sptSet[u] = 1;

        for (v = 0; v < nodes; v++)
            if (!sptSet[v] && adjMatrix[u][v] != INF && dist[u] != INF && dist[u] + adjMatrix[u][v] < dist[v])
            {
                parent[v] = u;
                dist[v] = dist[u] + adjMatrix[u][v];
            }
    }

    printf("Vertex   Distance from source vertex %d   \tPath\n", src + 1);
    for (i = 0; i < nodes; i++)
    {
        printf("%d \t\t ", i + 1);
        if (dist[i] == INF)
            printf("%c",236);
        else
            printf("%d", dist[i]);
        printf("\t\t\t\t ");
        if (dist[i] != INF)
            printPath(parent, i, src);
        else
            printf("No path");
        printf("\n");
    }
}


int main()
{
    int nodes, edges, weight, u, v, ch,i,j;
    int adjMatrix[MAX_NODES][MAX_NODES];

    for (i = 0; i < MAX_NODES; i++)
    {
        for (j = 0; j < MAX_NODES; j++)
            adjMatrix[i][j] = INF;
    }

    printf("Enter number of nodes in the graph: ");
    scanf("%d", &nodes);

    printf("Enter number of edges in the graph: ");
    scanf("%d", &edges);

    printf("1. Directed Graph\n2. Un-directed Graph\nEnter your choice: ");
    scanf("%d", &ch);

    switch (ch)
    {
        case 1:
            printf("Enter the edges (format: from_node to_node weight) (node value starts from 1): \n"); //node value starts from 1
            fflush(stdin);
            for (i = 0; i < edges; i++)
            {
                scanf("%d %d %d", &u, &v, &weight);
                addEdge_dir(u - 1, v - 1, weight, adjMatrix);
            }
            break;
        case 2:
            printf("Enter the edges (format: from_node to_node weight) (node value starts from 1): \n"); //node value starts from 1
            fflush(stdin);
            for (i = 0; i < edges; i++)
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

/*
Output: (FOR DIRECTED GRAPH)
------
Enter number of nodes in the graph: 5
Enter number of edges in the graph: 8
1. Directed Graph
2. Un-directed Graph
Enter your choice: 1
Enter the edges (format: from_node to_node weight) (node value starts from 1): 
1 2 10
2 4 1
1 3 5
3 2 3
3 4 9
5 1 2
3 5 2
5 4 6
Adjacency Matrix:
  0  10   5   ∞   ∞ 
  ∞   0   ∞   1   ∞ 
  ∞   3   0   9   2 
  ∞   ∞   ∞   0   ∞ 
  2   ∞   ∞   6   0 
Enter the source vertex: 1
Vertex   Distance from source vertex 1          Path
1                0                               1
2                8                               1 -> 3 -> 2
3                5                               1 -> 3
4                9                               1 -> 3 -> 2 -> 4
5                7                               1 -> 3 -> 5
*/

/*
Output: (FOR UN-DIRECTED GRAPH)
------
Enter number of nodes in the graph: 5
Enter number of edges in the graph: 8
1. Directed Graph
2. Un-directed Graph
Enter your choice: 2
Enter the edges (format: from_node to_node weight) (node value starts from 1): 
1 2 10
2 4 1
1 3 5
3 2 3
3 4 9
5 1 2
3 5 2
5 4 6
Adjacency Matrix:
  0  10   5   ∞   2 
 10   0   3   1   ∞ 
  5   3   0   9   2 
  ∞   1   9   0   6 
  2   ∞   2   6   0 
Enter the source vertex: 1
Vertex   Distance from source vertex 1          Path
1                0                               1
2                7                               1 -> 5 -> 3 -> 2
3                4                               1 -> 5 -> 3
4                8                               1 -> 5 -> 4
5                2                               1 -> 5
*/
