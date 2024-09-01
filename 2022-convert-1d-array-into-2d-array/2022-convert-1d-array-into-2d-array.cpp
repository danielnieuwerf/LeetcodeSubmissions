class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        auto arrayLength = original.size();
        if(arrayLength != m*n) return {};
        vector<vector<int>> ans;
        ans.reserve(m);
        for(int i = 0; i<arrayLength; i += n) {
            vector<int> row;
            row.reserve(n);
            for(int j = i; j<i+n; ++j)
                row.push_back(original[j]);
            ans.push_back(row);
        }
        
        return ans;
    }
};