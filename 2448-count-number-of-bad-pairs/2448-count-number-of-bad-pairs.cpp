class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        // j - i != nums[j] - nums[i] <=> nums[i] - i != nums[j] - j
    
        long long ans = 0;
        long long n = nums.size();
        unordered_map<int,int> mp;
        for(int i = 0; i<n; ++i)
            ++mp[nums[i] - i];
        
        long long goodPairs = 0;
        for(auto& p: mp) {
            goodPairs += (long long) (p.second - 1)*p.second / 2;
        }

        return n*(n-1)/2 - goodPairs;
    }
};