// **Variant 5: Using Bitmasking for Rows and Columns**
#include <vector>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    int rowMask = 0, colMask = 0;
    
    // Mark rows and columns to be zeroed
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 0) {
                rowMask |= (1 << i);
                colMask |= (1 << j);
            }
        }
    }
    
    // Set rows to zero
    for (int i = 0; i < m; ++i) {
        if (rowMask & (1 << i)) {
            for (int j = 0; j < n; ++j) {
                matrix[i][j] = 0;
            }
        }
    }
    
    // Set columns to zero
    for (int j = 0; j < n; ++j) {
        if (colMask & (1 << j)) {
            for (int i = 0; i < m; ++i) {
                matrix[i][j] = 0;
            }
        }
    }
}
