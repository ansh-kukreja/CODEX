#include<iostream>
#include<list>
using namespace std;


class Graph{
    public:
    unordered_map<int, list<int>> adj;  // Adjaceny List of each Vertex

    void addEdge(int u, int v, bool direction){
        // True -> directed
        // False -> undirected

        adj[u].push_back(v);

        if(direction == 0){
            adj[v].push_back(u);
        }
    }

    void printAdjList(){
        cout<<endl<<"---- Adjaceny List of Graph ----"<<endl;
        for(auto i: adj){
            cout<<i.first<<" -> ";
            
            for(auto j: i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
};

int main(){
    int n,m;
    cout<<"Enter the Number of Vertices: ";
    cin>>n;

    cout<<"Enter the Number of Edges: ";
    cin>>m;

    Graph g;

    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;

        g.addEdge(u,v,0);
    }

    g.printAdjList();
}