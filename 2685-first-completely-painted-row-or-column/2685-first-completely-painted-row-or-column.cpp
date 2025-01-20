class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> rows(n, 0);
        vector<int> cols(m, 0);
        unordered_map<int, pair<int,int>> mp{};
        for(int i = 0; i<n; ++i)
            for(int j = 0; j<m; ++j) {
                mp[mat[i][j]] = make_pair(i,j);
            }

        for(int i = 0; i<arr.size(); ++i) {
            auto p = mp[arr[i]];
            ++rows[p.first];
            ++cols[p.second];
            if(rows[p.first] == m || cols[p.second] == n) {
                return i;
            }
        }
        return -1;
    }
};