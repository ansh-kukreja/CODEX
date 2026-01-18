#include<iostream>
using namespace std;

void bfs(vector<vector<int>> &adj, unordered_map<int,bool> &visited, vector<int> &ans, int node){
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        
        ans.push_back(frontNode);
        
        for(auto k : adj[frontNode]){
            if(!visited[k]){
                q.push(k);
                visited[k] = true;
            }
        }
        
    }
}


int main(){

    vector<vector<int>> adj = {{2,3,1}, {0}, {0,4}, {0}, {2}};


    vector<int> ans;
    unordered_map<int,bool> visited;
    
    for(int i=0; i<adj.size(); i++){
        if(!visited[i]){
            bfs(adj, visited, ans, i);
        }
    }


    cout<<"\n-------- BFS TRAVERSAL -------\n";
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n-----------------------------\n";
}
