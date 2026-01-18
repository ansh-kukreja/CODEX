#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
#include<list>
using namespace std;


class Solution {
  public:
  
  void topSort(int node, unordered_map<int,bool> &visited, stack<int> &s,
  unordered_map<int,list<int>> &adj){
      visited[node] = 1;
      
      for(auto neighbour: adj[node]){
          if(!visited[neighbour]){
              topSort(neighbour, visited, s, adj);
          }
      }
      
      s.push(node);
  }
  

    // ========== Main Function ==========
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int, list<int>> adj;
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
        }
        
        unordered_map<int,bool> visited;
        stack<int> s;
        
        for(int i=0; i<V; i++){
            if(!visited[i]){
                topSort(i, visited, s, adj);
            }
        }
        
        vector<int> ans;
        
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        
        return ans;
    }
};