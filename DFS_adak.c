#include <stdio.h>

#define MAX_NODES 100

void addEdge(int u, int v, int adjMatrix[MAX_NODES][MAX_NODES]) //node value starts from 1
{
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = -1;
}

void displayMatrix(int nodes, int adjMatrix[MAX_NODES][MAX_NODES])
{
	int i, j;
    printf("Adjacency Matrix:\n");
    for (i = 0; i < nodes; i++)
    {
        for (j = 0; j < nodes; j++)
            printf("%3d ", adjMatrix[i][j]);
        printf("\n");
    }
}

void DFS(int startNode, int nodes, int adjMatrix[MAX_NODES][MAX_NODES])
{
	static int visited[MAX_NODES];
	int stack[MAX_NODES], current, top=-1, i;
	
	visited[startNode] = 1;
	stack[++top] = startNode;
	
	printf("DFS Traversal starting from node %d: ",startNode+1);
	
	while(top != -1)
	{
		current = stack[top--];
		printf("%d ",current + 1);
		
		for(i = 0; i < nodes; i++)
		{
			if(adjMatrix[current][i] == 1 && visited[i] == 0)
			{
				visited[i] = 1;
				stack[++top] = i;
			}
		}
	}
}

int main()
{
    int i, nodes, edges, u, v;
    static int adjMatrix[MAX_NODES][MAX_NODES];

    printf("Enter number of nodes in the graph: ");
    scanf("%d", &nodes);

    printf("Enter number of edges in the graph: ");
    scanf("%d", &edges);

    printf("Enter the edges (format: from_node to_node) (node value starts from 1):\n"); //node value starts from 1
    for (i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);
        addEdge(u-1, v-1, adjMatrix);
    }

    displayMatrix(nodes, adjMatrix);

    printf("\nEnter the starting node for DFS traversal: ");
    scanf("%d", &u);
    DFS(u-1, nodes, adjMatrix);
    
    return 0;
}

/*
Output:
------
Enter number of nodes in the graph: 5
Enter number of edges in the graph: 5
Enter the edges (format: from_node to_node) (node value starts from 1):
1 2
1 3
1 4
3 4
3 5
Adjacency Matrix:
  0   1   1   1   0
 -1   0   0   0   0
 -1   0   0   1   1
 -1   0  -1   0   0
  0   0  -1   0   0

Enter the starting node for DFS traversal: 1
DFS Traversal starting from node 1: 1 4 3 5 2
--------------------------------
Process exited after 16.56 seconds with return value 0
Press any key to continue . . .
*/
