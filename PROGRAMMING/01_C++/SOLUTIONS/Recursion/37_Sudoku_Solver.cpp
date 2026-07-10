#include<iostream>
using namespace std;


class Solution {
public:

    bool isSafe(int row, int col, vector<vector<char>>& board, int val) {
        char num = '0' + val;

        for (int i=0; i<9; i++) {
            // checking row and column
            if (board[row][i] == num || board[i][col] == num)
                return false;

            // checking current grid
            if ( board[3 * (row/3) + i/3][3 * (col/3) + i%3] == num )
                return false;
        }

        return true;
    }

    bool solve(vector<vector<char>>& board) {
        
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                if (board[i][j] == '.') {

                    for (int val=1; val<=9; val++) {
                        if (isSafe(i, j, board, val)) {
                            board[i][j] = '0' + val;

                            bool isPossible = solve(board);

                            if (isPossible)
                                return true;
                            
                            if (!isPossible)
                                board[i][j] = '.';
                        }
                    }
                    return false;

                }
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};


int main(){
    
}