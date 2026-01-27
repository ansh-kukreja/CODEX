#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;


class Solution {
  public:
    bool checkCycleDFS(int node, unordered_map<int,bool> &visited,
    unordered_map<int,bool> &dfsVisited, unordered_map<int, list<int>> &adj){
        visited[node] = true;
        dfsVisited[node] = true;
        
        for(auto k: adj[node]){
            if(!visited[k]){
                bool cycleDetected = checkCycleDFS(k, visited, dfsVisited, adj);
                if(cycleDetected) return true;
            }
            else if(dfsVisited[k]){
                return true;
            }
        }
        
        dfsVisited[node] = false;
        return false;
    }
    

    // ==== Main Function ====
    bool isCyclic(int V, vector<vector<int>> &edges) {
        unordered_map<int, list<int>> adj;
        
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
        }
        
        unordered_map<int,bool> visited;
        unordered_map<int,bool> dfsVisited;
        
        for(int i=1; i<=V; i++){
            if(!visited[i]){
                bool cycleFound = checkCycleDFS(i, visited,  dfsVisited, adj);
                if(cycleFound) return true;
            }
        }
        return false;
        
    }
};