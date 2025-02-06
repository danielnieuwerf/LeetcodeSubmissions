class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int ans = 0;
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i = 0; i<n-1; ++i)
            for(int j = i+1; j<n; ++j) {
                auto count = ++mp[nums[i]*nums[j]];
                if(count > 1) {
                    ans += 8 *(count-1);
                }
            }
        return ans;
    }
};