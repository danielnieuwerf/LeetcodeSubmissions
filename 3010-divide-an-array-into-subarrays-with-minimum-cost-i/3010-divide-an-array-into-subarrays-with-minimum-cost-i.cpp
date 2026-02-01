class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int best = 1e9;
        int n = nums.size();
        for(int i = 1; i<n-1;++i) {
            for(int j = i+1;j<n;++j)
                best = min(best, nums[i]+nums[j]);
        }

        return nums[0] + best;
    }
};