// **Variant 1: Using Additional Memory**
#include <vector>
#include <unordered_set>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    unordered_set<int> rows, cols;
    
    // Mark rows and columns to be zeroed
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 0) {
                rows.insert(i);
                cols.insert(j);
            }
        }
    }
    
    // Set rows to zero
    for (int row : rows) {
        for (int j = 0; j < n; ++j) {
            matrix[row][j] = 0;
        }
    }
    
    // Set columns to zero
    for (int col : cols) {
        for (int i = 0; i < m; ++i) {
            matrix[i][col] = 0;
        }
    }
}
