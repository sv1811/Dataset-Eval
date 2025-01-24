// **Variant 4: Using Separate Arrays for Rows and Columns**
#include <vector>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<bool> rows(m, false), cols(n, false);
    
    // Mark rows and columns to be zeroed
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 0) {
                rows[i] = true;
                cols[j] = true;
            }
        }
    }
    
    // Set rows to zero
    for (int i = 0; i < m; ++i) {
        if (rows[i]) {
            for (int j = 0; j < n; ++j) {
                matrix[i][j] = 0;
            }
        }
    }
    
    // Set columns to zero
    for (int j = 0; j < n; ++j) {
        if (cols[j]) {
            for (int i = 0; i < m; ++i) {
                matrix[i][j] = 0;
            }
        }
    }
}
