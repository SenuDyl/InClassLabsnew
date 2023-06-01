// C++ program for Dijkstra's single source shortest path
// algorithm. The program is for adjacency matrix
// representation of the graph
#include <iostream>
using namespace std;
#include <limits.h>
#include <vector>

const int Vertices = 6;

void dijkstra(int graph[Vertices][Vertices], int source)
{
    vector<int> distance(Vertices, INT_MAX); // Stores the shortest distances from the source
    vector<bool> visited(Vertices, false);   // Keeps track of visited vertices
    for (int i = 0; i < Vertices; i++)
        distance[i] = INT_MAX, visited[i] = false;

    distance[source] = 0; // Distance from source to itself is 0

    // Perform Dijkstra's algorithm
    for (int count = 0; count < Vertices - 1; count++)
    {
        int minimum = INT_MAX;
        int min_index = -1;

        // Find the vertex with the minimum distance
        for (int k = 0; k < Vertices; k++)
        {
            if (distance[k] <= minimum && visited[k] == false)
            {
                min_index = k;
                minimum = distance[k];
            }
        }
        int final_min = min_index;

        visited[final_min] = true; // Mark the vertex as visited

        // Update the distances of adjacent vertices
        for (int v = 0; v < Vertices; v++)
        {
            if (!visited[v] && graph[final_min][v] && distance[final_min] != INT_MAX)
            {
                if (distance[final_min] + graph[final_min][v] < distance[v])
                {
                    distance[v] = distance[final_min] + graph[final_min][v];
                }
            }
        }
    }

    // Print the shortest distances from the source
    cout << "Shortest distances from the source: " << source << endl;

    for (int i = 0; i < Vertices; ++i)
    {
        cout << source << "->" << i << " = " << distance[i] << " ";
    }
    cout << endl;
}

int main()
{
    int graph[6][6] = {{0, 10, 0, 0, 15, 5},
                       {10, 0, 10, 30, 0, 0},
                       {0, 10, 0, 12, 5, 0},
                       {0, 30, 12, 0, 0, 20},
                       {15, 0, 5, 0, 0, 0},
                       {5, 0, 0, 20, 0, 0}};

    for (int i = 0; i <= 5; i++)
    {
        dijkstra(graph, i);
    }

    return 0;
}
