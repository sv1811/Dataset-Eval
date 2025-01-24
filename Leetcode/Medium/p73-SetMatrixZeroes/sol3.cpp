// **Variant 3: Space-Optimized Approach**
#include <vector>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    bool firstColZero = false;
    
    for (int i = 0; i < m; ++i) {
        if (matrix[i][0] == 0) firstColZero = true;
        for (int j = 1; j < n; ++j) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    
    for (int i = m - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 1; --j) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
        if (firstColZero) matrix[i][0] = 0;
    }
}
