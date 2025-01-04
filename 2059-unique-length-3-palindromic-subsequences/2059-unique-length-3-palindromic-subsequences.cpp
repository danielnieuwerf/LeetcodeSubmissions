class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0;
        for(char c = 'a'; c<='z'; ++c) {
            size_t pos1 = s.find_first_of(c);
            if(pos1 == string::npos) continue;
            size_t pos2 = s.find_last_of(c);
            if(pos2 == string::npos || pos2 == pos1) continue;
            unordered_set<char> us;
            for(auto i = pos1 +1; i < pos2; ++i)
                us.insert(s[i]);
            ans += us.size();
        }
        return ans;
    }
};