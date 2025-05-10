class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto num: nums)
            ++mp[num];
        int ans = 0;
        for(auto p: mp) {
            if(mp.find(p.first-1) != mp.end()) {
                ans = max(ans, p.second + mp[p.first-1]);
            }
            if(mp.find(p.first+1) != mp.end()) {
                ans = max(ans, p.second + mp[p.first+1]);
            }
        }
        return ans;
    }
};