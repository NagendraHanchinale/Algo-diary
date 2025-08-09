class DisjointSet {
    vector<int> parent, size;
public: 
    // O(n)
    DisjointSet(int n) {
        parent.resize(n + 1, 0);
        size.resize(n + 1);
        for (int i = 0; i < n + 1; ++i) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    // O(α(n))  [α = Inverse Ackermann Function, nearly constant]
    int find(int u) {
        if (u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }
    
    // O(α(n))
    void unionSize(int u, int v) {
        int ul_u = find(u);
        int ul_v = find(v);
        if (ul_u == ul_v) return;
        if (size[ul_u] > size[ul_v]) {
            parent[ul_v] = ul_u;
            size[ul_u] += size[ul_v];
        } else {
            parent[ul_u] = ul_v;
            size[ul_v] += size[ul_u]; 
        }
    }
};

class Solution {
public:
    // O(E log E + E α(V))  [Kruskal’s Algorithm]
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<pair<int, pair<int, int>>> adj;
        
        // Building adjacency list: O(E)
        for (auto it : edges) {
            adj.push_back({it[2], {it[0], it[1]}});
        }
        
        // Sorting edges by weight: O(E log E)
        sort(adj.begin(), adj.end());
        
        int mst = 0;
        DisjointSet ds(V);
        
        // Processing edges: O(E α(V))
        for (auto it : adj) {
            int w = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if (ds.find(u) != ds.find(v)) {
                ds.unionSize(u, v);
                mst += w;
            }
        }
        
        return mst;
    }
};
