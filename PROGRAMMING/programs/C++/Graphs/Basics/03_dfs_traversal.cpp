#include<iostream>
using namespace std;

void dfs(vector<vector<int>> &adj, unordered_map<int,bool> &visited, vector<int> &ans, int node){
        
    ans.push_back(node);
    visited[node] = 1;
    
    for(auto i: adj[node]){
        if(!visited[i]){
            dfs(adj, visited, ans, i);
        }
    }
}


int main(){

    vector<vector<int>> adj = {{2,3,1}, {0}, {0,4}, {0}, {2}};

    vector<int> ans;
    unordered_map<int,bool> visited;
    
    for(int i=0; i<adj.size(); i++){
        if(!visited[i]){
            dfs(adj, visited, ans, i);
        }
    }


    cout<<"\n-------- DFS TRAVERSAL -------\n";
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n-----------------------------\n";
}
