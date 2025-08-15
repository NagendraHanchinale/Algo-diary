class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> indeg(V , 0) , ans;
        vector<vector<int>> graph(V);
        queue<int> q;
        for(auto it : edges){
            indeg[it[1]]++;
            graph[it[0]].push_back(it[1]);
        }
        for(int i = 0 ;i < V ; ++i)if(indeg[i] == 0)q.push(i);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : graph[node]){
                indeg[it]--;
                if(indeg[it] == 0)q.push(it);
            }
        }
        return ans;
        
    }
};
