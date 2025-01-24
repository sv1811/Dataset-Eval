#include<bits/stdc++.h>
using namespace std;

class Solution {
    char rows[9][9] = {0};
    char cols[9][9] = {0};
public:
    void solveSudoku(vector<vector<char>>& board) {
        for(int r = 0; r < 9; ++r) {
            for(int c = 0; c < 9; ++c) {
                if(!(board[r][c] == '.')) {
                    char val = board[r][c];
                    rows[r][val - '1'] = val;
                    cols[c][val - '1'] = val;
                }
            }
        }
        solve(board);
    }

private:
    bool solve(auto& board) {
        for(int row = 0; row < 9; ++row) {
            for(int col = 0; col < 9; ++col) {
                if(board[row][col] == '.') {
                    for(char num = '1'; num <= '9'; ++num) {
                        if(isValid(board, row, col, num)) {
                            board[row][col] = num;
                            rows[row][num - '1'] = num;
                            cols[col][num - '1'] = num;
                            if(solve(board)) return true;
                            rows[row][num - '1'] = '.';
                            cols[col][num - '1'] = '.';
                            board[row][col] = '.';
                        }
                    }

                    return false;
                }
            }
        }
        
        return true;
    }

    bool isValid(auto& board, int row, int col, char num) {
        if(rows[row][num - '1'] == num || cols[col][num - '1'] == num) return false;
        
        row = (row / 3) * 3, col = (col / 3) * 3;

        for(int r = row; r < row + 3; ++r) {
            for(int c = col; c < col + 3; ++c) {
                if(board[r][c] == num) {
                    return false;
                }
            }
        } 

        return true;
    }
};