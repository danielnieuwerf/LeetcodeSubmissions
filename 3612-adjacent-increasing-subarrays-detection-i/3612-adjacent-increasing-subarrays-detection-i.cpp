class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        if(k == 1) {
            return true;
        }
        int curr = 1;
        int prev = 0;
        for(int i = 1; i<nums.size(); ++i) {
            if(nums[i] > nums[i-1]) {
                ++curr;
                if(curr >= 2 * k) {
                    return true;
                }
            } else {
                prev = curr;
                curr = 1;
            }
            if(prev >= k && curr >= k) {
                return true;
            }
        }
        return false;
    }
};