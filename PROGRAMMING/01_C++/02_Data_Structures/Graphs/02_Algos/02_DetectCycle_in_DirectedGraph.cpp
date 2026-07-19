#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;


class Solution {
  public:
  
    bool checkCycleDFS(
        int node,
        unordered_map<int,bool> &visited,
        unordered_map<int,bool> &currVisited, 
        unordered_map<int, list<int>> &adj)
    {
        visited[node] = true;
        currVisited[node] = true;
        
        for(auto k: adj[node]){
            if(!visited[k]){
                bool cycleDetected = checkCycleDFS(k, visited, currVisited, adj);
                if(cycleDetected) return true;
            }
            else if(currVisited[k]){
                return true;
            }
        }
        
        currVisited[node] = false;
        return false;
    }

    


    bool checkCycleBFS (int n, vector<vector<int>> &edges) {

        // Making Adjacency List
        unordered_map<int, list<int>> adj;

        for (int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
        }
        

        // Finding Indegrees of All Nodes
        vector<int> indegree(n);

        for (auto i : adj) {
            for(auto j : i.second){
                indegree[j]++;
            }
        }
        

        // Pushing Initial Nodes with 0 Indegree
        queue<int> q;
        
        for (int i=0; i<n; i++) {

            if(indegree[i] == 0)
                q.push(i);
        }
        

        // Doing BFS
        int count = 0;
        
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            
            count++;
            
            for (auto ngb: adj[front]) {

                indegree[ngb]--;

                if(indegree[ngb] == 0)
                    q.push(ngb);
            }
        }
        
        if (count == n) return false;
        else return true;
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
        unordered_map<int,bool> currVisited;
        
        for(int i=1; i<=V; i++){
            if(!visited[i]){
                bool cycleFound = checkCycleDFS(i, visited,  currVisited, adj);
                if(cycleFound) return true;
            }
        }
        return false;
        
    }
};