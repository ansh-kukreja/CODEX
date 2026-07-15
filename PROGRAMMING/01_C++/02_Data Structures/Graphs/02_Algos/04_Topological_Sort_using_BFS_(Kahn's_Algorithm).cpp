#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<vector>

using namespace std;

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {

        // Making Adjacency List
        unordered_map<int, list<int>> adj;

        for (int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
        }
        

        // Finding Indegrees of All Nodes
        vector<int> indegree(V);

        for (auto i : adj) {
            for(auto j : i.second){
                indegree[j]++;
            }
        }
        

        // Pushing Initial Nodes with 0 Indegree
        queue<int> q;
        
        for (int i=0; i<V; i++) {

            if(indegree[i] == 0)
                q.push(i);
        }
        

        // Doing BFS
        vector<int> ans;
        
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            
            ans.push_back(front);
            
            for (auto ngb: adj[front]) {

                indegree[ngb]--;

                if(indegree[ngb] == 0)
                    q.push(ngb);
            }
        }
        
        return ans;
    }
};