class NumMatrix {
    int _n;
    int _m;
    vector<vector<int>> _prefixSums;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        _n = matrix.size();
        _m = matrix[0].size();
        _prefixSums = vector<vector<int>>(_n, vector<int>(_m+1, 0));
        for(int i = 0; i<_n; ++i) {
            _prefixSums[i][1] = matrix[i][0];
            for(int j = 1; j<_m; ++j) {
                _prefixSums[i][j+1] = _prefixSums[i][j] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = 0;
        for(int row = row1; row <= row2; ++row) {
            ans += _prefixSums[row][col2+1]-_prefixSums[row][col1];
        }
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */