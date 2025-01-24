// Variant 3: Iterative Stack-based DFS
#include <vector>
#include <stack>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    vector<int> inDegree(numCourses, 0);
    for (const auto& p : prerequisites) {
        graph[p[1]].push_back(p[0]);
        inDegree[p[0]]++;
    }
    
    stack<int> stack;
    vector<bool> visited(numCourses, false);
    vector<int> result;
    
    for (int i = 0; i < numCourses; i++) {
        if (inDegree[i] == 0) stack.push(i);
    }
    
    while (!stack.empty()) {
        int curr = stack.top(); stack.pop();
        if (visited[curr]) continue;
        
        visited[curr] = true;
        result.push_back(curr);
        
        for (int next : graph[curr]) {
            if (--inDegree[next] == 0) stack.push(next);
        }
    }
    
    return result.size() == numCourses ? result : vector<int>();
}
