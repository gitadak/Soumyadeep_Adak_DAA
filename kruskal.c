#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

typedef struct
{
    int u, v, w;
} edge;

typedef struct
{
    edge *data;
    int n;
} edge_list;

void addEdge(int u, int v, int weight, int adjMatrix[MAX_NODES][MAX_NODES])
{
    adjMatrix[u][v] = weight;
    adjMatrix[v][u] = weight; // considering an undirected graph
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

int find(int belongs[], int vertexno)
{
    return (belongs[vertexno]);
}

void applyUnion(int belongs[], int c1, int c2)
{
    int i;

    for (i = 0; i < MAX_NODES; i++)
    {
        if (belongs[i] == c2)
            belongs[i] = c1;
    }
}

void sort(edge_list *elist)
{
    int i, j;
    edge temp;

    for (i = 1; i < elist->n; i++)
        for (j = 0; j < elist->n - 1; j++)
            if (elist->data[j].w > elist->data[j + 1].w) {
                temp = elist->data[j];
                elist->data[j] = elist->data[j + 1];
                elist->data[j + 1] = temp;
            }
}

void kruskalAlgo(int nodes, int adjMatrix[MAX_NODES][MAX_NODES], edge_list *elist, edge_list *spanlist)
{
    int belongs[MAX_NODES], i, j, cno1, cno2;
    elist->n = 0;

    for (i = 1; i < nodes; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (adjMatrix[i][j] != 0)
            {
                elist->data[elist->n].u = i;
                elist->data[elist->n].v = j;
                elist->data[elist->n].w = adjMatrix[i][j];
                elist->n++;
            }
        }
    }

    sort(elist);

    for (i = 0; i < nodes; i++)
        belongs[i] = i;

    spanlist->n = 0; // Initialize spanlist

    for (i = 0; i < elist->n; i++) {
        cno1 = find(belongs, elist->data[i].u);
        cno2 = find(belongs, elist->data[i].v);

        if (cno1 != cno2) {
            spanlist->data[spanlist->n] = elist->data[i];
            spanlist->n = spanlist->n + 1;
            applyUnion(belongs, cno1, cno2);
        }
    }
}

void print(edge_list *spanlist)
{
    int i, cost = 0;
    printf("Edge   Weight\n");
    for (i = 0; i < spanlist->n; i++)
    {
        printf("%d - %d    %d\n", spanlist->data[i].u + 1, spanlist->data[i].v + 1, spanlist->data[i].w);
        cost = cost + spanlist->data[i].w;
    }

    printf("Minimal Spanning tree cost = %d", cost);
}

int main()
{
    int nodes, edges, weight, u, v;
    edge_list elist;
    edge_list spanlist;
    int adjMatrix[MAX_NODES][MAX_NODES]={0};

    printf("Enter number of nodes in the graph: ");
    scanf("%d", &nodes);

    printf("Enter number of edges in the graph: ");
    scanf("%d", &edges);

    elist.data = malloc(edges * sizeof(edge));
    spanlist.data = malloc(edges * sizeof(edge));

    printf("Enter the edges (format: from_node to_node weight) (node value starts from 1): \n"); //node value starts from 1
    for (int i = 0; i < edges; i++)
    {
        scanf("%d %d %d", &u, &v, &weight);
        addEdge(u - 1, v - 1, weight, adjMatrix);
    }

    kruskalAlgo(nodes, adjMatrix, &elist, &spanlist);
    displayMatrix(nodes,adjMatrix);
    print(&spanlist);

    free(elist.data);
    free(spanlist.data);

    return 0;
}
/*
Output:
------
Enter number of nodes in the graph: 5
Enter number of edges in the graph: 6
Enter the edges (format: from_node to_node weight) (node value starts from 1):
3 1 3
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
5 - 4    1
4 - 3    2
3 - 1    3
4 - 2    4
Minimal Spanning tree cost = 10
*/

