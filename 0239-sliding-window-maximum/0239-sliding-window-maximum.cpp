class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int, int> mp;
        int n = nums.size();
        vector<int> ans(n-k+1, 0);
        for(int i = 0; i<k; ++i)
            ++mp[nums[i]];
        for(int i = 0; i<n-k+1; ++i) {
            ans[i] = mp.rbegin()->first;
            if(i+k<n)
                ++mp[nums[i+k]];
            auto x = --mp[nums[i]];
            if(x == 0) {
                mp.erase(nums[i]);
            }
        }
        return ans;
    }
};