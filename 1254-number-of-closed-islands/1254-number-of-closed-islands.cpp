class Solution {
    int n;
    int m;
    
    int total = 0;
public:
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        vector<vector<int>> current;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        for(int i = 1; i<n-1; ++i)
            for(int j = 1; j<m-1; ++j)
            {
                current.clear();
                dfs(i,j, visited, grid, current);
                if(current.size() && isClosed(current))++total;
                    
            }
            
        return total;
    }
    
    void dfs(int row, int col, vector<vector<bool>>& visited, vector<vector<int>>& grid, vector<vector<int>>& current)
    {
        if(row<0 || row>=n || col<0 || col>=m || visited[row][col] || grid[row][col] == 1)return;
        
        visited[row][col] = true;
        current.push_back({row, col});
        
        dfs(row - 1, col, visited, grid, current);
        dfs(row + 1, col, visited, grid, current);
        dfs(row, col + 1, visited, grid, current);
        dfs(row, col - 1, visited, grid, current);

    }
    
    bool isClosed(vector<vector<int>>& current)
    {
        for(auto landPiece : current)
        {
            if(landPiece[0] == 0 || landPiece[0] == n-1 || landPiece[1] == 0 || landPiece[1] == m -1)
                return false;
        }
        
        return true;
    }
};