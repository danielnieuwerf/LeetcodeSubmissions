class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int curr = 1;
        unordered_map<int,int> mp{};
        while(l<=r && r<n) {
            ++mp[nums[r]];
            while(mp[nums[r]] > k) {
                --mp[nums[l]];
                ++l;
            }
            curr = max(curr, r-l+1);
            ++r;
        }
        return curr;
    }
};