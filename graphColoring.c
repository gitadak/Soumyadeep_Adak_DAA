#include <stdio.h>

#define MAX_NODES 100

// Function to print the solution
void printSolution(int color[], int nodes)
{
    int i;
    printf("Solution Exists: Following are the assigned colors\n");
    for (i = 0; i < nodes; i++)
        printf("Vertex %d ---> Color %d\n", i + 1, color[i]);
}

// Function to check if the current color assignment is safe for vertex v
int isSafe(int v, int graph[MAX_NODES][MAX_NODES], int color[], int c, int nodes)
{
    int i;
    for (i = 0; i < nodes; i++)
        if (graph[v][i] && c == color[i])
            return 0;
    return 1;
}

// A recursive utility function to solve the graph coloring problem
int graphColoringUtil(int graph[MAX_NODES][MAX_NODES], int m, int color[], int v, int nodes)
{
    int c;

    // Base case: If all vertices are assigned a color then return true
    if (v == nodes)
        return 1;

    // Consider this vertex v and try different colors
    for (c = 1; c <= m; c++)
    {
        // Check if assignment of color c to v is safe
        if (isSafe(v, graph, color, c, nodes))
        {
            color[v] = c;

            // Recur to assign colors to the rest of the vertices
            if (graphColoringUtil(graph, m, color, v + 1, nodes))
                return 1;

            // If assigning color c doesn't lead to a solution then remove it (backtrack)
            color[v] = 0;
        }
    }

    // If no color can be assigned to this vertex then return false
    return 0;
}

// This function solves the m Coloring problem using backtracking. It returns false if the m colors cannot be assigned, otherwise it returns true and prints the assignments of colors to all vertices.
int graphColoring(int graph[MAX_NODES][MAX_NODES], int m, int nodes)
{
    // Initialize all color values as 0. This initialization is needed for the correct functioning of isSafe()
    int color[MAX_NODES] = {0};

    // Call graphColoringUtil() for vertex 0
    if (!graphColoringUtil(graph, m, color, 0, nodes))
    {
        printf("Solution does not exist\n");
        return 0;
    }

    printSolution(color, nodes);
    return 1;
}

// Function to display the adjacency matrix
void displayMatrix(int graph[MAX_NODES][MAX_NODES], int nodes)
{
    int i,j;
    printf("Adjacency Matrix:\n");
    for (i = 0; i < nodes; i++)
    {
        for (j = 0; j < nodes; j++)
            printf("%3d ", graph[i][j]);
        printf("\n");
    }
}

int main()
{
    int nodes, edges, u, v, i;
    int graph[MAX_NODES][MAX_NODES] = {0};  // Initialize the graph with no edges

    printf("Enter number of nodes in the graph: ");
    scanf("%d", &nodes);

    printf("Enter number of edges in the graph: ");
    scanf("%d", &edges);

    printf("Enter the edges (format: from_node to_node) (node value starts from 1): \n");
    for (i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);
        graph[u - 1][v - 1] = 1;
        graph[v - 1][u - 1] = 1;
    }

    int m; // Number of colors
    printf("Enter the number of colors: ");
    scanf("%d", &m);

    // Display the adjacency matrix
    displayMatrix(graph, nodes);

    // Solve the m-coloring problem
    graphColoring(graph, m, nodes);

    return 0;
}

/*
Output:
------
Enter number of nodes in the graph: 4
Enter number of edges in the graph: 3
Enter the edges (format: from_node to_node) (node value starts from 1): 
1 2
2 3
3 4
Enter the number of colors: 5
Adjacency Matrix:
  0   1   0   0 
  1   0   1   0 
  0   1   0   1 
  0   0   1   0 
Solution Exists: Following are the assigned colors
Vertex 1 ---> Color 1
Vertex 2 ---> Color 2
Vertex 3 ---> Color 1
Vertex 4 ---> Color 2
*/