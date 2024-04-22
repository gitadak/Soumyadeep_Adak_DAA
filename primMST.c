//Minimum cost spanning tree (MST) by Prim's algorithm
//For un-directed graph

#include <stdio.h>

#define MAX_NODES 100
#define INF 9999

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
                printf("%3d ", 0);
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

int minKey(int key[MAX_NODES], int mstSet[MAX_NODES], int nodes)
{
    int min = INF, min_index = -1,v;
    for (v = 0; v < nodes; v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

void primMST(int nodes, int adjMatrix[MAX_NODES][MAX_NODES])
{
    int parent[MAX_NODES], key[MAX_NODES], net_weight=0, u, mstSet[MAX_NODES],i,count;

    for (i = 0; i < nodes; i++)
    {
        key[i] = INF;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (count = 0; count < nodes - 1; count++)
    {
        u = minKey(key, mstSet, nodes);
        mstSet[u] = 1;
        for (int v = 0; v < nodes; v++)
            // Check if the edge exists and it is either not included in MST or has a weight less than the current key
            if (adjMatrix[u][v] <= key[v] && !mstSet[v])
            {
                parent[v] = u;
                key[v] = adjMatrix[u][v];
            }
    }

    printf("Edge   Weight\n");
    for (i = 1; i < nodes; i++)
    {
        net_weight += adjMatrix[i][parent[i]];
        printf("%d - %d    %d \n", parent[i]+1, i+1, adjMatrix[i][parent[i]]);
    }
    printf("Minimal Spanning tree cost = %d",net_weight);
}

int main()
{
    int nodes, edges, weight, u, v, i,j;
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

    printf("Enter the edges (format: from_node to_node weight) (node value starts from 1): \n"); //node value starts from 1
    fflush(stdin);
    for (i = 0; i < edges; i++)
    {
        scanf("%d %d %d", &u, &v, &weight);
        addEdge_undir(u - 1, v - 1, weight, adjMatrix);
    }

    displayMatrix(nodes, adjMatrix);

    primMST(nodes, adjMatrix);

    return 0;
}

/*
Output:
------
Enter number of nodes in the graph: 6
Enter number of edges in the graph: 8
Enter the edges (format: from_node to_node weight) (node value starts from 1): 
1 2 5
2 3 7
4 5 0
5 6 2
1 4 11
2 5 3
3 6 3
3 5 1
Adjacency Matrix:
  0   5   ∞  11   ∞   ∞ 
  5   0   7   ∞   3   ∞ 
  ∞   7   0   ∞   1   3 
 11   ∞   ∞   0   0   ∞ 
  ∞   3   1   0   0   2 
  ∞   ∞   3   ∞   2   0 
Edge   Weight
1 - 2    5 
5 - 3    1 
5 - 4    0 
2 - 5    3 
5 - 6    2 
Minimal Spanning tree cost = 11
*/
