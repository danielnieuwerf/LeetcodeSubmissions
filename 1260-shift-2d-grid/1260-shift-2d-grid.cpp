class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        if(k == 0)
            return grid;
        int n = grid.size();
        int m = grid[0].size();
        vector<int> flat;
        for(int i = 0; i<n; ++i) {
            for(int j = 0; j<m; ++j) {
                flat.push_back(grid[i][j]);
            }
        }

        k = k%(m*n);
        int start = n*m - k;
        for(int i = 0; i<n; ++i) {
            for(int j = 0; j<m; ++j) {
                grid[i][j] = flat[start%(m*n)];
                ++start;
            }
        }

        return grid;
    }
};