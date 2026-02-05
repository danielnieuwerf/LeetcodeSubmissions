class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        for(int i = 0; i<n; ++i) {
            if (nums[i] == 0) {
                ans[i] = nums[i];
                continue;
            }
            ans[i] = nums[mod(i + nums[i], n)];
        }
        return ans;
    }

    int mod(int x, int y) {
        return ((x % y) + y) % y;
    }
};