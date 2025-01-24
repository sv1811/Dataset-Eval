// Variant 1: Kahn's Algorithm with Queue
#include <vector>
#include <queue>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    vector<int> inDegree(numCourses, 0);
    for (const auto& p : prerequisites) {
        graph[p[1]].push_back(p[0]);
        inDegree[p[0]]++;
    }
    
    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
        if (inDegree[i] == 0) q.push(i);
    }
    
    vector<int> result;
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        result.push_back(curr);
        for (int next : graph[curr]) {
            if (--inDegree[next] == 0) q.push(next);
        }
    }
    return result.size() == numCourses ? result : vector<int>();
}
