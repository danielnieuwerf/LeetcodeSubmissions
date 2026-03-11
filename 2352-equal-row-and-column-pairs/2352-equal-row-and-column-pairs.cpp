class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        vector<vector<int>> rows;
        for(int i = 0; i<n; ++i) {
            rows.push_back(grid[i]);
        }
        vector<vector<int>> cols;
        for(int i = 0; i<n; ++i) {
            vector<int> col;
            for(int j = 0; j<n; ++j) {
                col.push_back(grid[j][i]);
            }
            cols.push_back(col);
        }
        for(int i = 0; i<n; ++i) {
            for(int j = 0; j<n; ++j) {
                if (rows[i] == cols[j]) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};