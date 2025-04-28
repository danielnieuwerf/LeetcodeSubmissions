class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n < 2) 
            return n;
        int l = 0;
        int r = 0;
        int ans = 0;
        unordered_set <char> us;
        while(r != n){
            if(us.find(s[r]) != us.end()) {
                us.erase(s[l]);
                ++l;
            } else {
                ans = max(r-l+1, ans);
                us.insert(s[r]);
                ++r;
            }
        }
        return ans;
    }
};