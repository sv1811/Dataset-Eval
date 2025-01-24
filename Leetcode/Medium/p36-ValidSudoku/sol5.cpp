// **Variant 5: Using Bitmasking with Single Integer**
#include <vector>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    vector<int> rows(9, 0), cols(9, 0), boxes(9, 0);
    
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] == '.') continue;
            
            int num = board[i][j] - '1'; // Convert to 0-based index
            int boxIndex = (i / 3) * 3 + (j / 3);
            
            // Check row, column, and sub-box
            if ((rows[i] & (1 << num)) || (cols[j] & (1 << num)) || (boxes[boxIndex] & (1 << num))) return false;
            
            rows[i] |= (1 << num);
            cols[j] |= (1 << num);
            boxes[boxIndex] |= (1 << num);
        }
    }
    
    return true;
}
