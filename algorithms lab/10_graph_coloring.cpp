#include <iostream>
using namespace std;

#define V 4 // Number of vertices in the graph

// Function to print the solution
void printSolution(int color[])
{
    cout << "Solution exists: Following are the assigned colors:\n";
    for (int i = 0; i < V; i++)
        cout << "Vertex " << i << " ---> Color " << color[i] << endl;
}

// Utility function to check if the current color assignment is safe for vertex v
bool isSafe(int v, bool graph[V][V], int color[], int c)
{
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}

// A recursive utility function to solve the graph coloring problem
bool graphColoringUtil(bool graph[V][V], int m, int color[], int v)
{
    // Base case: If all vertices are assigned a color then return true
    if (v == V)
        return true;

    // Consider this vertex v and try different colors
    for (int c = 1; c <= m; c++)
    {
        // Check if assignment of color c to v is fine
        if (isSafe(v, graph, color, c))
        {
            color[v] = c;

            // Recur to assign colors to the rest of the vertices
            if (graphColoringUtil(graph, m, color, v + 1))
                return true;

            // If assigning color c doesn't lead to a solution then remove it (backtrack)
            color[v] = 0;
        }
    }

    // If no color can be assigned to this vertex then return false
    return false;
}

// Function to solve the m Coloring problem using backtracking
bool graphColoring(bool graph[V][V], int m)
{
    // Initialize all color values as 0. This initialization is needed to handle the case when no colors are assigned to any vertex
    int color[V] = {0};

    // Call graphColoringUtil() for vertex 0
    if (graphColoringUtil(graph, m, color, 0) == false)
    {
        cout << "Solution does not exist" << endl;
        return false;
    }

    // Print the solution
    printSolution(color);
    return true;
}

int main()
{
    // Create the following graph and test it
    // (3)---(2)
    //  |   / |
    //  |  /  |
    //  | /   |
    // (0)---(1)
    bool graph[V][V] = {{0, 1, 1, 1},
                        {1, 0, 1, 0},
                        {1, 1, 0, 1},
                        {1, 0, 1, 0}};

    int m = 3; // Number of colors
    graphColoring(graph, m);
    return 0;
}
