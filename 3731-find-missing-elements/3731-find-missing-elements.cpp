class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int current = nums[0];
        for(int i = 1; i<nums.size(); ++i) {
            int curr = nums[i] - current;
            int k = 1;
            while(curr > 1) {
                ans.push_back(current + k);
                ++k;
                curr--;
            }
            current = nums[i];
        }
        return ans;
    }
};