class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> mp;
        for(auto w: words) {
            ++mp[w];
        }
        int ans = 0;
        bool usedMiddle = false;
        for(auto w: words) {
            if(w[0] == w[1] && mp[w] == 1 && !usedMiddle) {
                ans += 2;
                usedMiddle = true;
                --mp[w];
                continue;
            }
            string s;
            s += w[1];
            s += w[0];
            if(mp.find(s) == mp.end()) {
                continue;
            }
            if(mp[s]>0 && mp[w] > 0) {
                if(s[0] == s[1] && mp[s] <= 1)
                    continue;
                --mp[s];
                --mp[w];
                ans += 4;
            }
        }

        return ans;
    }
};