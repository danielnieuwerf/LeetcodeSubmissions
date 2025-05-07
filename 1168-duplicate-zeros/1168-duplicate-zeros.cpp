class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, 0);   
        int i = 0, j = 0;
        for(; j<n; ++i, ++j) {
            ans[j] = arr[i];
            if(arr[i] == 0 && j < n-1) {
                ans[j+1] = 0;
                ++j;
            }
        }
        arr = ans;
    }
};