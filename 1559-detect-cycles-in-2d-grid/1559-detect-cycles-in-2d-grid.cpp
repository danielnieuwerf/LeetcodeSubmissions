class Solution {
    int m, n;
    vector<vector<bool>> visited;

public:
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!visited[i][j]) {
                    if (dfs(grid, i, j, -1, -1)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& grid, int x, int y, int px, int py) {
        visited[x][y] = true;

        const vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        for (auto& [dx, dy] : dirs) {
            int nx = x + dx;
            int ny = y + dy;
            if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if (grid[nx][ny] != grid[x][y]) continue;
            if (nx == px && ny == py) continue;
            if (visited[nx][ny]) return true;
            if (dfs(grid, nx, ny, x, y)) return true;
        }

        return false;
    }
};