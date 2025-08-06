class Solution {
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = -1;
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (grid[i][j] == 2)
                    q.push({{i, j}, 0});

        while (!q.empty()) {
            auto data = q.front();
            auto [x, y] = data.first;
            int time = data.second;
            ans = max(ans, time);
            q.pop();
            for (auto [dx, dy] : dir) {
                int nx = x + dx;
                int ny = y + dy;
                if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
                    grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    q.push({{nx, ny}, time + 1});
                }
            }
        }
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (grid[i][j] == 1)
                    return -1;

        return ans;
    }
};
