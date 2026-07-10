#include<iostream>
using namespace std;


class Solution {
  public:
  
    bool isSafe(int newX, int newY, vector<vector<bool>> &vis, vector<vector<int>> &arr, int n) {
        if ((newX >= 0 && newX < n) && (newY >= 0 && newY < n) && 
            (vis[newX][newY] == 0) && (arr[newX][newY] == 1) )
            return true;
        
        return false;
    }

    void solve(int x, int y, vector<vector<int>> &arr, int n, vector<string> &ans, 
    vector<vector<bool>> &vis, string path) {
    
        if (x == n-1 && y == n-1) {
            ans.push_back(path);
            return;
        }
    
        //  D, L, R, U
    
        if (isSafe(x+1, y, vis, arr, n)) {
            vis[x][y] = 1;
            solve(x+1, y, arr, n, ans, vis, path+'D');
            vis[x][y] = 0;
        }
        if (isSafe(x, y-1, vis, arr, n)) {
            vis[x][y] = 1;
            solve(x, y-1, arr, n, ans, vis, path+'L');
            vis[x][y] = 0;
        }
        if (isSafe(x, y+1, vis, arr, n)) {
            vis[x][y] = 1;
            solve(x, y+1, arr, n, ans, vis, path+'R');
            vis[x][y] = 0;
        }
        if (isSafe(x-1, y, vis, arr, n)) {
            vis[x][y] = 1;
            solve(x-1, y, arr, n, ans, vis, path+'U');
            vis[x][y] = 0;
        }
    }
    
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        vector<string> ans;
        vector<vector<bool>> visited(n, vector<bool>(n,0));
        string path = "";
    
        if (maze[0][0] == 0) return ans;
    
        solve(0, 0, maze, n, ans, visited, path);
        return ans;
    }
};




int main(){
    
}