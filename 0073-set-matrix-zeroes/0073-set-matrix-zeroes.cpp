class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        set<int> cols;
        set<int> rows;
        for(int i = 0; i<n; ++i) {
            for(int j = 0; j<m; ++j) {
                if(matrix[i][j] == 0) {
                    cols.insert(j);
                    rows.insert(i);
                }
            }
        }
        for(auto val: cols) {
            for(int i = 0; i<n; ++i) {
                matrix[i][val] = 0;
            }
        }
        for(auto val: rows) {
            for(int j = 0; j<m; ++j) {
                matrix[val][j] = 0;
            }
        }
    }
};