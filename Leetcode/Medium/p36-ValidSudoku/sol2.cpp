// **Variant 2: Using Bitmasking for Rows, Columns, and Sub-boxes**
#include <vector>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    vector<int> rows(9, 0), cols(9, 0), boxes(9, 0);
    
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] == '.') continue;
            
            int num = board[i][j] - '0';
            int mask = 1 << num;
            
            // Check row
            if (rows[i] & mask) return false;
            rows[i] |= mask;
            
            // Check column
            if (cols[j] & mask) return false;
            cols[j] |= mask;
            
            // Check sub-box
            int boxIndex = (i / 3) * 3 + (j / 3);
            if (boxes[boxIndex] & mask) return false;
            boxes[boxIndex] |= mask;
        }
    }
    
    return true;
}
