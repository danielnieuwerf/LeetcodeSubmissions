class Solution {
public:
    int minimumLength(string s) {
        unordered_map<int,int> mp;
        for(auto c: s) {
            if(auto x = ++mp[c]; x>2) {
                mp[c] = 1;
            }
        }
        int ans = 0;
        for(auto p: mp)
            ans += p.second;
        return ans;
    }
};