class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i<n; ++i) {
            for(int j = 0; j<m; ++j) {
                if(i+3 > n || j+3 > m) continue;
                int x = grid[i][j] + grid[i][j+1] + grid[i][j+2];
                int x2 = grid[i+1][j] + grid[i+1][j+1] + grid[i+1][j+2];
                int x3 = grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2];
                if(x != 15 || x2 != 15 || x3 != 15) continue; // check rows
                x = grid[i][j] + grid[i+1][j] + grid[i+2][j];
                x2 = grid[i][j+1] + grid[i+1][j+1] + grid[i+2][j+1];
                x3 = grid[i][j+2] + grid[i+1][j+2] + grid[i+2][j+2];
                if(x != 15 || x2 != 15 || x3 != 15) continue; // check columns
                x = grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2];
                x2 = grid[i+2][j] + grid[i+1][j+1] + grid[i][j+2];
                if(x != 15 || x2 != 15) continue; // check diags
                map<int,int> mp;
                for(int k = 0; k<3; ++k) {
                    ++mp[grid[i+k][j]];
                    ++mp[grid[i+k][j+1]];
                    ++mp[grid[i+k][j+2]];
                }
                if(mp.size() != 9 || mp.rbegin()->first != 9 || mp.begin()->first != 1) continue; // check every element 1-9 exists
                ++ans;
            }
        }
        return ans;
    }
};