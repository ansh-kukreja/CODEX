#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
#include<list>
using namespace std;


class Solution {
  public:
  
  void topologicalSort(
    int node, 
    unordered_map<int,bool> &visited, 
    stack<int> &s,
    unordered_map<int, vector<pair<int, int>>> adj) 
  {
      visited[node] = 1;
      
      for(auto ngb : adj[node]){
          if(!visited[ngb.first]){
              topologicalSort(ngb.first, visited, s, adj);
          }
      }
      
      s.push(node);
  }
  

    // ========== Main Function ==========
    //                                               Node -> [ {Neighbour, Cost}, {Neighbour, Cost} ]
    vector<int> shortestDistanceInWeightedDAG(int V, unordered_map<int, vector<pair<int, int>>> adj) {

        unordered_map<int,bool> visited;
        stack<int> s;
        
        for(int i=0; i<V; i++){
            if(!visited[i]){
                topologicalSort(i, visited, s, adj);
            }
        }
        
        
        int src = 1;
        vector<int> dist(V, INT_MAX);

        dist[src] = 0;

        while (!s.empty()) {
            int top = s.top();
            s.pop();

            if (dist[top] != INT_MAX) {
                for (auto i : adj[top]) {
                    if (dist[top] + i.second < dist[i.first]) {
                        dist[i.first] = dist[top] + i.second;
                    }
                }
            }
        }
    }
};