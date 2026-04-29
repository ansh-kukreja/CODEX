#include <iostream>
using namespace std;

#define MAX 100

int adj[MAX][MAX];
bool visited[MAX];
int level[MAX];
int queueArr[MAX];

void BFS(int V, int source) {
    int front = 0, rear = 0;

    for (int i = 0; i < V; i++) {
        visited[i] = false;
        level[i] = -1;
    }

    visited[source] = true;
    level[source] = 0;
    queueArr[rear++] = source;

    cout << "BFS Traversal: ";

    while (front < rear) {
        int node = queueArr[front++];
        cout << node << " ";

        for (int i = 0; i < V; i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                visited[i] = true;
                level[i] = level[node] + 1;
                queueArr[rear++] = i;
            }
        }
    }

    cout << "\n\nNode Levels from Source (" << source << "):\n";
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << " -> Level " << level[i] << endl;
    }
}

int main() {
    int V, E;

    cout << "Enter number of vertices: "; 
    cin >> V;

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;

    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        // Undirected graph
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    BFS(V, source);

    return 0;
}