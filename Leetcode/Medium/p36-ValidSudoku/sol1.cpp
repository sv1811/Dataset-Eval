// **Variant 1: Using Hash Sets for Rows, Columns, and Sub-boxes**
#include <vector>
#include <unordered_set>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    vector<unordered_set<char>> rows(9), cols(9), boxes(9);
    
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            char num = board[i][j];
            if (num == '.') continue;
            
            // Check row
            if (rows[i].count(num)) return false;
            rows[i].insert(num);
            
            // Check column
            if (cols[j].count(num)) return false;
            cols[j].insert(num);
            
            // Check sub-box
            int boxIndex = (i / 3) * 3 + (j / 3);
            if (boxes[boxIndex].count(num)) return false;
            boxes[boxIndex].insert(num);
        }
    }
    
    return true;
}
