#include <bits/stdc++.h>
using namespace std;
#define V 5

int minKey(int dist[V], bool sptSet[V])
{
    int min = INT_MAX, min_index;
    for (int i = 0; i < V; i++)
    {
        if (!sptSet[i] && dist[i] < min)
        {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void printDijkstra(int dist[V])
{
    for (int i = 0; i < V; i++)
    {
        cout << i << "  " << dist[i] << endl;
    }
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V];
    bool sptSet[V];

    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0;

    for (int i = 0; i < V - 1; i++)
    {
        int u = minKey(dist, sptSet);

        sptSet[u] = true;
        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && !sptSet[v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printDijkstra(dist);
}

int main()
{
    int graph[V][V] = {{0, 10, 20, 0, 0},
                       {10, 0, 0, 50, 10},
                       {20, 0, 0, 20, 33},
                       {0, 50, 20, 0, 2},
                       {0, 10, 33, 2, 0}};

    int src = 0;
    dijkstra(graph, src);
    return 0;
}