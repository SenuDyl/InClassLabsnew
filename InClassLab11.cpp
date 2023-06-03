#include<iostream>
#include<vector>
using namespace std;

const int Vertices = 6;

// Finding the minimum spanning tree using Prim's Algorithm
void PrimsAlgo(int graph[Vertices][Vertices], int src) {
    // Create vectors to store key values, MST information, and parent vertices
    vector<int> key(Vertices, INT_MAX);
    vector<bool> mst(Vertices, false);
    vector<int> parent(Vertices);
    
    parent[src] = -1;
    key[src] = 0;
    
    for (int i = 0; i < Vertices; i++) {
        int minimum = INT_MAX;
        int minIndex;
        
        // Find the vertex with the minimum key value that is not yet included in MST
        for (int j = 0; j < Vertices; j++) {
            if (key[j] < minimum && mst[j] == false) {
                minimum = key[j];
                minIndex = j;
            }
        }
        
        mst[minIndex] = true;
        
        // Update key values and parent vertices of the adjacent vertices
        for (int k = 0; k < Vertices; k++) {
            if (graph[minIndex][k] && mst[k] == false && graph[minIndex][k] < key[k]) {
                key[k] = graph[minIndex][k];
                parent[k] = minIndex;
            }
        }
    }
    
    cout << "Edge \tWeight\n";
    
    // Print the constructed MST
    for (int t = 1; t < Vertices; t++) {
        cout << parent[t] << " - " << t << " \t" << graph[t][parent[t]] <<endl;
    }
}

int main() {
    int graph[Vertices][Vertices] = {
        {0, 3, 0, 0, 0, 1},
        {3, 0, 2, 1, 10, 0},
        {0, 2, 0, 3, 0, 5},
        {0, 1, 3, 0, 5, 0},
        {0, 10, 0, 5, 0, 4},
        {1, 0, 5, 0, 4, 0}
    };
    
    PrimsAlgo(graph, 0);
    
    return 0;
}
