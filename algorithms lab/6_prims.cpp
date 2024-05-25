#include <bits/stdc++.h>
using namespace std;
#define V 5

int minKey(int key[V], bool mstSet[V])
{
    int min = INT_MAX, min_index;
    for (int i = 0; i < V; i++)
    {
        if (!mstSet[i] && key[i] < min)
        {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

void printMst(int parent[V], int graph[V][V])
{
    for (int i = 1; i < V; i++)
    {
        cout << parent[i] << " - " << i << "  " << graph[i][parent[i]] << endl;
    }
}

void primMst(int graph[V][V])
{
    int parent[V];
    int key[V];
    bool mstSet[V];

    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < V - 1; i++)
    {
        int u = minKey(key, mstSet);

        mstSet[u] = true;
        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
            {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }
    printMst(parent, graph);
}

int main()
{
    int graph[V][V] = {{0, 2, 0, 6, 0},
                       {2, 0, 3, 8, 5},
                       {0, 3, 0, 0, 7},
                       {6, 8, 0, 0, 9},
                       {0, 5, 7, 9, 0}};

    primMst(graph);
    return 0;
}