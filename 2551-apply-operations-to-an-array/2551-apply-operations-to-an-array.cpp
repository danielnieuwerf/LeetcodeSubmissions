class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i = 0; i<nums.size()-1; ++i) {
            if(nums[i] == nums[i+1]) {
                nums[i] *= 2;
                nums[i+1] = 0;
            }
        }

        int zeroes = 0;
        for(auto num: nums)
            if(num == 0)
                ++zeroes;

        vector<int> ans;
        for(auto num: nums)
            if(num != 0)
                ans.push_back(num);
        while(zeroes--) {
            ans.push_back(0);
        }
        return ans;
    }
};