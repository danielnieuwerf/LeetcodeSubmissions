class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, 0);   
        int j = 0;
        for(int i = 0; j<n; ++i, ++j) {
            if(arr[i] == 0) {
                ans[j] = 0;
                if(j<n-1)
                    ans[j+1] = 0;
                ++j;
            } else {
                ans[j] = arr[i];
            }
        }
        arr = ans;
    }
};