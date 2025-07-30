#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        set<pair<int,int>> s;
        vector<int> dis(V , 1e9);
        vector<int> parent(V); 

        for (int i = 0; i < V; ++i) parent[i] = i;

        vector<vector<pair<int,int>>> adj(V);
        for(auto it : edges){
            adj[it[0]].push_back({it[1] , it[2]});
            adj[it[1]].push_back({it[0] , it[2]});
        }

        s.insert({0 , src});
        dis[src] = 0;

        while(!s.empty()){
            auto it = *(s.begin());
            int node = it.second;
            int distance = it.first;
            s.erase(it);

            for(auto edge : adj[node]){
                int adjNode = edge.first;
                int adjWeight = edge.second;
                if(distance + adjWeight < dis[adjNode]){
                    if(dis[adjNode] != 1e9){
                        s.erase({dis[adjNode] , adjNode});
                    }
                    dis[adjNode] = distance + adjWeight;
                    parent[adjNode] = node; 
                    s.insert({dis[adjNode] , adjNode});
                }
            }
        }

        for (int dest = 0; dest < V; ++dest) {
            cout << "Path from " << src << " to " << dest << ": ";
            printPath(dest, parent);
            cout << " (Cost: " << dis[dest] << ")\n";
        }

        return dis;
    }

    void printPath(int node, vector<int>& parent) {
        if (node == parent[node]) {
            cout << node << " ";
            return;
        }
        printPath(parent[node], parent);
        cout << node << " ";
    }
};
