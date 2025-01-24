// **Variant 3: Using Arrays for Rows, Columns, and Sub-boxes**
#include <vector>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    bool rows[9][9] = {false}, cols[9][9] = {false}, boxes[9][9] = {false};
    
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] == '.') continue;
            
            int num = board[i][j] - '1'; // Convert to 0-based index
            int boxIndex = (i / 3) * 3 + (j / 3);
            
            // Check row, column, and sub-box
            if (rows[i][num] || cols[j][num] || boxes[boxIndex][num]) return false;
            
            rows[i][num] = cols[j][num] = boxes[boxIndex][num] = true;
        }
    }
    
    return true;
}
