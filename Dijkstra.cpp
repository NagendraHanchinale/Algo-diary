// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>> adj(V);
        for(auto it : edges){
            adj[it[0]].push_back({it[1] , it[2]});
            adj[it[1]].push_back({it[0] , it[2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        q.push({0,src});
        vector<int> dis(V , 1e9);
        dis[src] = 0;
        while(!q.empty()){
            int d = q.top().first;
            int node = q.top().second;
            q.pop();
            for(auto it : adj[node]){
                int an = it.first;
                int ew = it.second;
                if(d + ew < dis[an]){
                    dis[an] = ew + d;
                    q.push({dis[an] , an});
                }
                
            }
        }
        return dis;
    }
};
