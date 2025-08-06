class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> dis(V , 1e8);
        dis[src] = 0;
        for(int i = 0 ; i < V ; ++i){
            for(auto it : edges){
                int u = it[0] , v = it[1] , w = it[2];
                if(dis[u] + w < dis[v] && dis[u] != 1e8){
                    dis[v] = dis[u] + w;
                }
            }
        }

            for(auto it : edges){
                int u = it[0] , v = it[1] , w = it[2];
                if(dis[u] + w < dis[v] && dis[u] != 1e8){
                    return {-1};
                }
            }
        
        return dis;
    }
};
