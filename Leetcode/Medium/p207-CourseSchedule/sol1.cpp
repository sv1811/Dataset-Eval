// Variant 1: Kahn's Algorithm with Queue
#include <vector>
#include <queue>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
    
    int count = 0;
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        count++;
        for (int next : graph[curr]) {
            inDegree[next]--;
            if (inDegree[next] == 0) q.push(next);
        }
    }
    return count == numCourses;
}
