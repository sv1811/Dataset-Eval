// Variant 4: BFS with Adjacency Matrix
#include <vector>
#include <queue>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<bool>> matrix(numCourses, vector<bool>(numCourses, false));
    vector<int> inDegree(numCourses, 0);
    
    for (const auto& p : prerequisites) {
        if (!matrix[p[1]][p[0]]) {
            matrix[p[1]][p[0]] = true;
            inDegree[p[0]]++;
        }
    }
    
    queue<int> q;
    vector<int> result;
    
    for (int i = 0; i < numCourses; i++) {
        if (inDegree[i] == 0) q.push(i);
    }
    
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        result.push_back(curr);
        
        for (int next = 0; next < numCourses; next++) {
            if (matrix[curr][next] && --inDegree[next] == 0) {
                q.push(next);
            }
        }
    }
    
    return result.size() == numCourses ? result : vector<int>();
}
