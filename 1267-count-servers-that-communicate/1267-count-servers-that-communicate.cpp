class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<bool> visitedRow(n, false);
        vector<bool> visitedCol(m, false);
        set<int> rows;
        set<int> cols;
        unordered_map<int,int> mp;
        unordered_map<int,int> mp2;
        for(int i = 0; i<n; ++i)
            for(int j = 0; j<m; ++j) {
                if(grid[i][j] == 1) {
                    if(visitedRow[i] || visitedCol[j]) {
                        ++ans;
                        visitedRow[i] = true;
                        visitedCol[j] = true;
                    } else {
                        visitedRow[i] = true;
                        visitedCol[j] = true;
                        rows.insert(i);
                        cols.insert(j);
                        mp[i] = j;
                        mp2[j] = i;
                        continue;
                    }
                    // try match non matched servers.
                    if(rows.contains(i)) {
                        ++ans;
                        rows.erase(i);
                        cols.erase(mp[i]);
                    }
                    if(cols.contains(j)) {
                        ++ans;
                        cols.erase(j);
                        rows.erase(mp2[j]);
                    }
                }
            }
        return ans;
    }
};