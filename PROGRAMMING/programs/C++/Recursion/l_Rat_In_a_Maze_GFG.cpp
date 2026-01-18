#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isValid(vector<vector<int>> m, int n, int srcx, int srcy, vector<vector<int>> visited){
    if( (srcx >= 0 && srcx < n) && (srcy >= 0 && srcy < n) && visited[srcx][srcy] == 0 
        && m[srcx][srcy] == 1){
        return true;
    }
    else{
        return false;
    }
}

void solve(vector<vector<int>>& m, int n, int srcx, int srcy, string path, 
    vector<string> &ans, vector<vector<int>> visited ){
    
    if(srcx == n-1 && srcy == n-1){
        ans.push_back(path);
        return;
    }   
    
    visited[srcx][srcy] = 1;
    
    // Down
    int newx = srcx + 1;
    int newy = srcy;
    if(isValid(m, n, srcx, srcy, visited)){
        path.push_back('D');
        solve(m , n, newx, newy, path, ans, visited);
        path.pop_back();
    }
    
    // Up
    newx = srcx - 1;
    newy = srcy;
    if(isValid(m, n, srcx, srcy, visited)){
        path.push_back('U');
        solve(m , n, newx, newy, path, ans, visited);
        path.pop_back();
    }
    
    // Left
    newx = srcx;
    newy = srcy - 1;
    if(isValid(m, n, srcx, srcy, visited)){
        path.push_back('L');
        solve(m , n, newx, newy, path, ans, visited);
        path.pop_back();
    }
    
    // Right
    newx = srcx;
    newy = srcy + 1;
    if(isValid(m, n, srcx, srcy, visited)){
        path.push_back('R');
        solve(m , n, newx, newy, path, ans, visited);
        path.pop_back();
    }
    
    
    visited[srcx][srcy] = 0;
}

vector<string> findPath(vector<vector<int>> &m, int n) {
    int srcx = 0;
    int srcy = 0;
    string path = "";
    vector<string> ans;
    vector<vector<int>> visited;
    
    if(m[0][0] == 0){
        return ans;   
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            visited[i][j] = 0;
        }
    }
    
    solve(m , n, srcx, srcy, path, ans, visited);
    sort(ans.begin(), ans.end());
    
    return ans;
}

int main(){
    vector<vector<int>> m = {{1,0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    int n = 4;
    vector<string> ans = findPath(m,n);
    
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}
