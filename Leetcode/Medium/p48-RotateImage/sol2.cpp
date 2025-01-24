// **Variant 2: Layer-by-Layer Rotation**
#include <vector>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    
    for (int layer = 0; layer < n / 2; ++layer) {
        int first = layer;
        int last = n - 1 - layer;
        
        for (int i = first; i < last; ++i) {
            int offset = i - first;
            int top = matrix[first][i];
            
            // Move left to top
            matrix[first][i] = matrix[last - offset][first];
            
            // Move bottom to left
            matrix[last - offset][first] = matrix[last][last - offset];
            
            // Move right to bottom
            matrix[last][last - offset] = matrix[i][last];
            
            // Move top to right
            matrix[i][last] = top;
        }
    }
}
