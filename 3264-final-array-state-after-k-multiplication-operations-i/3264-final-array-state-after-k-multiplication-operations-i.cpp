class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if(k==0) return nums;
        int smallest = INT_MAX;
        int index = 0;
        for(int i = 0; i<nums.size(); ++i) {
            if(nums[i]<smallest) {
                smallest = nums[i];
                index = i;
            }
        }
        nums[index] *= multiplier;
        return getFinalState(nums, k - 1, multiplier);
    }
};