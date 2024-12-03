class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans;
        int j = 0;
        int len = spaces.size();
        int n = s.size();
        ans.reserve(n);
        for(int i = 0; i<n; ++i) {
            if(j<len && spaces[j] == i) {
                ++j;
                ans += " ";
            }
            ans += s[i];
        }
        return ans;
    }
};