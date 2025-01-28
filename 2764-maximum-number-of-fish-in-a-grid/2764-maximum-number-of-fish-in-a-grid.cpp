class Solution {
    int n = 0;
    int m = 0;
    set<long> visited;
public:
    int findMaxFish(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int best = 0;
        for(int i = 0; i<n; ++i) {
            for(int j = 0; j<m; ++j) {
                if(grid[i][j] == 0)
                    continue;
                best = max(best, dfs(grid, i, j));
            }
        }
        return best;
    }

    int dfs(vector<vector<int>>& grid, int i, int j) {
        if(i<0 || i>= n || j<0 || j>=m || visited.contains(i << 16 | j) || grid[i][j] == 0) return 0;
        visited.insert(i<<16 | j);
        return grid[i][j] + dfs(grid, i, j+1) + dfs(grid, i, j-1) + dfs(grid, i-1, j) + dfs(grid, i+1, j);
    }    
};