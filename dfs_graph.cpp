class Solution {
    void dfs(vector<vector<int>> &adj , vector<int> &vis , int node){
        vis[node] = 1;
        int n = adj.size();
        for(int j = 0; j < n; ++j){
            if(adj[node][j] == 1 && !vis[j]){
                dfs(adj , vis , j);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n , 0);
        int cnt = 0;
        for(int i = 0 ; i < n ; ++i){
            if(!vis[i]){
                cnt++;
                dfs(isConnected, vis, i);
            }
        }
        return cnt;
    }
};//time compleity - O(n ^ 2 ).
