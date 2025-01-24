// Variant 4: Union Find with Path Compression
#include <vector>
using namespace std;

class UnionFind {
private:
    vector<int> parent, rank;
    
public:
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false;
        
        if (rank[px] < rank[py]) swap(px, py);
        parent[py] = px;
        if (rank[px] == rank[py]) rank[px]++;
        return true;
    }
};

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    UnionFind uf(numCourses);
    for (const auto& p : prerequisites) {
        if (uf.find(p[0]) == uf.find(p[1])) return false;
        uf.unite(p[0], p[1]);
    }
    return true;
}
