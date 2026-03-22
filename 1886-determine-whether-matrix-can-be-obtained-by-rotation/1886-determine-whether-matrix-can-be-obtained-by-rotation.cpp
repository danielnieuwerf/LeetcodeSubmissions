class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        vector<bool> rotates(4, true);
        int n = mat.size();
        for(int i = 0; i<n; ++i) {
            for(int j = 0; j<n; ++j) {
                if(mat[i][j] != target[i][j]) rotates[0] = false;
                if(mat[i][j] != target[n-1-i][n-1-j]) rotates[1] = false;
                if(mat[i][j] != target[j][n-1-i]) rotates[2] = false;
                if(mat[i][j] != target[n-1-j][i]) rotates[3] = false;
            }
        }
        return rotates[0] || rotates[1] || rotates[2] || rotates[3];
    }
};