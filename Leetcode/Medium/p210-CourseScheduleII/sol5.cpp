// Variant 5: DFS with Colors and Priority Queue
#include <vector>
#include <queue>
using namespace std;

bool dfs(vector<vector<int>>& graph, vector<int>& colors, priority_queue<int>& pq, int node) {
    if (colors[node] == 1) return false;
    if (colors[node] == 2) return true;
    
    colors[node] = 1;
    for (int next : graph[node]) {
        if (!dfs(graph, colors, pq, next)) return false;
    }
    colors[node] = 2;
    pq.push(node);
    return true;
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    for (const auto& p : prerequisites) {
        graph[p[1]].push_back(p[0]);
    }
    
    vector<int> colors(numCourses, 0);
    priority_queue<int> pq;
    vector<int> result;
    
    for (int i = 0; i < numCourses; i++) {
        if (!colors[i] && !dfs(graph, colors, pq, i)) return {};
    }
    
    while (!pq.empty()) {
        result.push_back(pq.top());
        pq.pop();
    }
    
    reverse(result.begin(), result.end());
    return result;
}
