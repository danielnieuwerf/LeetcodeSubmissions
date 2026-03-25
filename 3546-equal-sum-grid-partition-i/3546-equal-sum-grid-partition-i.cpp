class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<long> rowSums(n, 0);
        vector<long> colSums(m, 0);
        for(int i = 0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                rowSums[i] += grid[i][j];
                colSums[j] += grid[i][j];
            }
        }

        vector<long> prefixRowSum(n,0);
        vector<long> prefixColSum(m,0);
        prefixRowSum[0] = rowSums[0];
        prefixColSum[0] = colSums[0];
        for(int i = 1; i<n; ++i) {
            prefixRowSum[i] = prefixRowSum[i-1] + rowSums[i];
        }
        for(int i = 1; i<m; ++i) {
            prefixColSum[i] = prefixColSum[i-1] + colSums[i];
        }

        for(int i = 0; i<n; ++i) {
            if(prefixRowSum[i] == prefixRowSum[n-1]-prefixRowSum[i])
                return true;
        }
        for(int i = 0; i<m; ++i) {
            if(prefixColSum[i] == prefixColSum[m-1]-prefixColSum[i])
                return true;
        }
        return false;
    }
};