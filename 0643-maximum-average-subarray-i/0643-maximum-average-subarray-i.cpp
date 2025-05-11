class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int r = k;
        double curr = 0;
        for(int i = l; i<r; ++i)
            curr += nums[i];
        double ans = curr/k;
        while(r<n) {
            curr += nums[r];
            curr -= nums[l];
            ans = max(ans, curr/k);
            ++r;
            ++l;
        }
        return ans;
    }
};