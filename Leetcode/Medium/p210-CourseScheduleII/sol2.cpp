// Variant 2: DFS with Cycle Detection and Post-Order Traversal
#include <vector>
using namespace std;

bool dfs(vector<vector<int>>& graph, vector<int>& visited, vector<int>& order, int node) {
    if (visited[node] == 1) return false;
    if (visited[node] == 2) return true;
    
    visited[node] = 1;
    for (int next : graph[node]) {
        if (!dfs(graph, visited, order, next)) return false;
    }
    visited[node] = 2;
    order.push_back(node);
    return true;
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    for (const auto& p : prerequisites) {
        graph[p[1]].push_back(p[0]);
    }
    
    vector<int> visited(numCourses, 0), order;
    for (int i = 0; i < numCourses; i++) {
        if (!visited[i] && !dfs(graph, visited, order, i)) return {};
    }
    reverse(order.begin(), order.end());
    return order;
}
