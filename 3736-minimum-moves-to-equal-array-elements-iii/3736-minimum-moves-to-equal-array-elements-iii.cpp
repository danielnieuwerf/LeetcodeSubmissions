class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans = 0;
        int target = *max_element(nums.begin(),nums.end());
        for(auto num: nums) {
            ans += (target-num);
        }
        return ans;
    }
};