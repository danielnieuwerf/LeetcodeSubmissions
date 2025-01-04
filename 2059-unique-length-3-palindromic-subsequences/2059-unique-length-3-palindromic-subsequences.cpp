class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0;
        for(char c = 'a'; c<='z'; ++c) {
            size_t pos1 = s.find_first_of(c);
            size_t pos2 = s.find_last_of(c);
            if(pos1 != string::npos && pos2 != string::npos && pos1 != pos2) {
                unordered_map<char,int> mp;
                for(auto i = pos1 +1; i < pos2; ++i)
                    ++mp[s[i]];
                ans += mp.size();
            }
        }
        return ans;
    }
};