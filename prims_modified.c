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
            if(adjMatrix[i][j]==0)
                printf("%3c ",236);
            else
                printf("%3d ", adjMatrix[i][j]);
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
    int parent[MAX_NODES], key[MAX_NODES], net_weight=0, u, mstSet[MAX_NODES], i, v, count;

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
        for (v = 0; v < nodes; v++)
            if (adjMatrix[u][v] && !mstSet[v] && adjMatrix[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = adjMatrix[u][v];
            }
    }

    printf("Edge   Weight\n");
    for (i = 1; i < nodes; i++)
    {
    	if(adjMatrix[i][parent[i]] == 0)
    	{
        	net_weight+=adjMatrix[parent[i]][i];
        	printf("%d - %d    %d \n", parent[i]+1, i+1, adjMatrix[parent[i]][i]);   		
		}
		else
		{
        	net_weight+=adjMatrix[i][parent[i]];
        	printf("%d - %d    %d \n", parent[i]+1, i+1, adjMatrix[i][parent[i]]);	
		}
    }
    printf("Minimal Spanning tree cost = %d",net_weight);
}

int main()
{
    int nodes, edges, weight, u, v, ch, i;
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

    primMST(nodes, adjMatrix);

    return 0;
}
