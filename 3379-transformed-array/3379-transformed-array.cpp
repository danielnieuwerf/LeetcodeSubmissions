class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        if(n==1) {
            return nums;
        }
        vector<int> ans(n, -1);
        for(int i = 0; i<n; ++i) {
            if (nums[i] != 0) {
                ans[i] = nums[mymod(i + nums[i], n)];
            } else {
                ans[i] = nums[i];
            }
        }
        return ans;
    }

    int mymod(int x, int y) {
        return ((x % y) + y) % y;
    }
};