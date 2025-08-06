#include <bits/stdc++.h>
using namespace std;

class PrimMST {
public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(V);
        for (auto &it : edges) {
            int u = it[0], v = it[1], w = it[2];
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }

        // Min-heap: {weight, {node, parent}}
        priority_queue< pair<int, pair<int, int>>, 
                        vector< pair<int, pair<int, int>> >, 
                        greater< pair<int, pair<int, int>> > > q;

        q.push({0, {0, -1}});
        vector<int> vis(V, 0);
        int totalWeight = 0;

        vector<vector<int>> mst;  

        while (!q.empty()) {
            auto [w, info] = q.top();
            q.pop();
            int node = info.first;
            int parent = info.second;

            if (vis[node]) continue;

            vis[node] = 1;
            totalWeight += w;

            if (parent != -1) {
                mst.push_back({parent, node, w});
            }

            for (auto &[nei, weight] : adj[node]) {
                if (!vis[nei]) {
                    q.push({weight, {nei, node}});
                }
            }
        }
      
        cout << "Edges in MST:\n";
        for (auto &edge : mst) {
            cout << edge[0] << " - " << edge[1] << " : " << edge[2] << "\n";
        }

        return totalWeight;
    }
};
