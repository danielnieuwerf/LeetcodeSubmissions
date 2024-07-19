class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans;
        
        for(int i = 0; i<n; ++i) {
            for(int j = 0; j<m; ++j)
            {
                if(matrix[i][j] == smallestVal(matrix[i])) {
                    vector<int> col;
                    for(int k = 0; k<n; ++k)
                        col.push_back(matrix[k][j]);
                    if(largestVal(col) == matrix[i][j])
                        ans.push_back(matrix[i][j]);
                    break;
                }
            }
        }
        
        return ans;
    }
    
    constexpr int largestVal(vector<int>& v) {
        return *std::max_element(v.begin(), v.end());
    }
    
    constexpr int smallestVal(vector<int>& v) {
        return *std::min_element(v.begin(), v.end());
    }
};