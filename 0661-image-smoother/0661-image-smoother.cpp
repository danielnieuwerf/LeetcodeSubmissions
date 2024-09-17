class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size();
        int m = img[0].size();
        vector<vector<int>> ans = vector<vector<int>>(n, vector<int>(m, 0));
        for(int i = 0; i<n; ++i)
            for(int j = 0; j<m; ++j) {
                int cnt = 1;
                int sum = img[i][j];
                if(i>0) {
                    ++cnt;
                    sum += img[i-1][j];
                    if(j>0) {
                        ++cnt;
                        sum += img[i-1][j-1];
                    }
                    if(j<m-1) {
                        ++cnt;
                        sum += img[i-1][j+1];
                    }
                }
                if(i<n-1) {
                    ++cnt;
                    sum += img[i+1][j];
                    if(j>0) {
                        ++cnt;
                        sum += img[i+1][j-1];
                    }
                    if(j<m-1) {
                        ++cnt;
                        sum += img[i+1][j+1];
                    }
                }
                if(j>0) {
                    ++cnt;
                    sum += img[i][j-1];
                }
                if(j<m-1) {
                    ++cnt;
                    sum += img[i][j+1];
                }
                ans[i][j] = sum/cnt;
            }
        
        return ans;
    }
};