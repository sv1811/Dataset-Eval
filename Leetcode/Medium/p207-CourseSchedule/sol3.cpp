// Variant 3: BFS with Adjacency Matrix
#include <vector>
#include <queue>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    // Using adjacency matrix instead of list
    vector<vector<bool>> matrix(numCourses, vector<bool>(numCourses, false));
    vector<int> inDegree(numCourses, 0);
    
    for (const auto& p : prerequisites) {
        if (!matrix[p[1]][p[0]]) {
            matrix[p[1]][p[0]] = true;
            inDegree[p[0]]++;
        }
    }
    
    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
        if (inDegree[i] == 0) q.push(i);
    }
    
    int count = 0;
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        count++;
        
        for (int next = 0; next < numCourses; next++) {
            if (matrix[curr][next]) {
                inDegree[next]--;
                if (inDegree[next] == 0) q.push(next);
            }
        }
    }
    return count == numCourses;
}
