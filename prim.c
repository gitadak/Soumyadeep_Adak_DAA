#include <stdio.h>

#define MAX_NODES 100
#define INF 9999

void addEdge(int u, int v, int weight, int adjMatrix[MAX_NODES][MAX_NODES])
{
    adjMatrix[u][v] = weight;
    adjMatrix[v][u] = weight; //considering un-directed graph
    /*for directed graph omit the above statement
    i.e. don't need to assign any weight to adjMatrix[v][u]*/
}

void displayMatrix(int nodes, int adjMatrix[MAX_NODES][MAX_NODES])
{
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < nodes; i++)
    {
        for (int j = 0; j < nodes; j++)
            if(adjMatrix[i][j]==0)
                printf("%3c ",236);
            else
                printf("%3d ", adjMatrix[i][j]);
        printf("\n");
    }
}

int minKey(int key[MAX_NODES], int mstSet[MAX_NODES], int nodes)
{
    int min = INF, min_index = -1;
    for (int v = 0; v < nodes; v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

void primMST(int nodes, int adjMatrix[MAX_NODES][MAX_NODES])
{
    int parent[MAX_NODES], key[MAX_NODES], net_weight=0, u, mstSet[MAX_NODES];

    for (int i = 0; i < nodes; i++)
    {
        key[i] = INF;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < nodes - 1; count++)
    {
        u = minKey(key, mstSet, nodes);
        mstSet[u] = 1;
        for (int v = 0; v < nodes; v++)
            if (adjMatrix[u][v] && !mstSet[v] && adjMatrix[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = adjMatrix[u][v];
            }
    }

    printf("Edge   Weight\n");
    for (int i = 1; i < nodes; i++)
    {
        net_weight+=adjMatrix[i][parent[i]];
        printf("%d - %d    %d \n", parent[i]+1, i+1, adjMatrix[i][parent[i]]);
    }
    printf("Minimal Spanning tree cost = %d",net_weight);
}

int main()
{
    int nodes, edges, weight, u, v;
    int adjMatrix[MAX_NODES][MAX_NODES] = {0};

    printf("Enter number of nodes in the graph: ");
    scanf("%d", &nodes);

    printf("Enter number of edges in the graph: ");
    scanf("%d", &edges);

    printf("Enter the edges (format: from_node to_node weight) (node value starts from 1): \n"); //node value starts from 1
    for (int i = 0; i < edges; i++)
    {
        scanf("%d %d %d", &u, &v, &weight);
        addEdge(u - 1, v - 1, weight, adjMatrix);
    }

    displayMatrix(nodes, adjMatrix);

    primMST(nodes, adjMatrix);

    return 0;
}

/*
Output:
------
Enter number of nodes in the graph: 5
Enter number of edges in the graph: 6
Enter the edges (format: from_node to_node weight) (node value starts from 1): 
1 3 3
3 5 6
3 4 2
3 2 10
2 4 4
4 5 1
Adjacency Matrix:
  ∞   ∞   3   ∞   ∞ 
  ∞   ∞  10   4   ∞ 
  3  10   ∞   2   6 
  ∞   4   2   ∞   1 
  ∞   ∞   6   1   ∞ 
Edge   Weight
4 - 2    4
1 - 3    3
3 - 4    2
4 - 5    1
Minimal Spanning tree cost = 10
*/