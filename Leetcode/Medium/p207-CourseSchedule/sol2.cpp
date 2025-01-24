// Variant 2: DFS with 3-Color Marking
#include <vector>
using namespace std;

bool dfs(vector<vector<int>>& graph, vector<int>& colors, int node) {
    if (colors[node] == 1) return true;  // Found cycle
    if (colors[node] == 2) return false; // Already processed
    
    colors[node] = 1;  // Mark as being processed
    for (int neighbor : graph[node]) {
        if (dfs(graph, colors, neighbor)) return true;
    }
    colors[node] = 2;  // Mark as processed
    return false;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    for (const auto& p : prerequisites) {
        graph[p[1]].push_back(p[0]);
    }
    
    vector<int> colors(numCourses, 0); // 0: unvisited, 1: processing, 2: processed
    for (int i = 0; i < numCourses; i++) {
        if (colors[i] == 0 && dfs(graph, colors, i)) return false;
    }
    return true;
}
