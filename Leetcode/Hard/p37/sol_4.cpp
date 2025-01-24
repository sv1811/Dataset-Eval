#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSafe(int row, int col, const vector<vector<char>>& sudoku,
                char val) {
        for (int i = 0; i <= 8; i++) {
            if (sudoku[row][i] == val) {
                return false;
            }

            if (sudoku[i][col] == val) {
                return false;
            }

            if (sudoku[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
                return false;
        }

        return true;
    }

    bool solve(vector<vector<char>>& sudoku) {
        for (int row = 0; row <= 8; row++) {
            for (int col = 0; col <= 8; col++) {
                if (sudoku[row][col] == '.') {
                    for (char val = '1'; val <= '9'; val++) {
                        if (isSafe(row, col, sudoku, val)) {
                            sudoku[row][col] = val;
                            if (solve(sudoku)) {
                                return true;
                            }
                            sudoku[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& sudoku) { solve(sudoku); }
};