class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        int target = *nums.rbegin();
        for(auto num: nums) {
            ans += (target-num);
        }
        return ans;
    }
};