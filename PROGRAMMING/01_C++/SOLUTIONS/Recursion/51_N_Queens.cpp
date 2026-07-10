#include<iostream>
using namespace std;


class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<string>> board;

    bool isSafe(int row, int col, int n) {
        int x = row;
        int y = col;

        while (y >= 0) {
            if (board[x][y] == "Q")
                return false;
            y--;
        }

        x = row;
        y = col;

        while (x >= 0 && y >= 0) {
            if (board[x][y] == "Q")
                return false;
            x--;
            y--;
        }

        x = row;
        y = col;

        while (x < n && y >= 0) {
            if (board[x][y] == "Q")
                return false;
            x++;
            y--;
        }

        return true;
    }

    void addSolution(int n) {
        vector<string> currSoln;

        for (int i=0; i<n; i++) {
            string row = "";
            for (int j=0; j<n; j++)
                row += board[i][j];
            
            currSoln.push_back(row);
        }

        ans.push_back(currSoln);
    }

    void solve(int col, int n) {

        if (col >= n) {
            addSolution(n);
            return;
        }

        for (int i=0; i<n; i++) {
            if (isSafe(i, col, n)) {
                board[i][col] = "Q";
                solve(col+1, n);
                board[i][col] = ".";
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> temp (n, vector<string> (n, "."));
        board = temp;

        solve(0, n);

        return ans;
    }
};


int main(){
    
}