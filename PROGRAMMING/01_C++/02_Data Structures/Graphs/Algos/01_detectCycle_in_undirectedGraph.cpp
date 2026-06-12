#include<iostream>
#include<unordered_map>
#include<queue>
#include<list>
using namespace std;


class Solution {
  public:
  
    bool isCyclicBFS(int src, unordered_map<int,bool> &visited, unordered_map<int,list<int>> &adj){
        
        unordered_map<int,int> parent;
        parent[src] = -1;
        visited[src] = 1;
        queue<int> q;
        q.push(src);
        
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            
            for(auto k: adj[frontNode]){
                
                if(visited[k] && k != parent[frontNode]){
                    // ==== CYCLE DETECTED ====
                    return true;
                }
                else if(!visited[k]){
                    q.push(k);
                    visited[k] = 1;
                    parent[k] = frontNode;
                }
                
            }
        }
        return false;
    }
  

    // ===== MAIN FUNCTION =====
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int, list<int>> adj;
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        unordered_map<int,bool> visited;
        
        for(int i=0; i<V; i++){
            if(!visited[i]){
                bool ans = isCyclicBFS(i, visited, adj);
                if(ans == 1) return true;
            }
        }
        return false;
    }
};