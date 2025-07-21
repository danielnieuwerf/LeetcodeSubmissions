class Solution {
public:
    string makeFancyString(string s) {
        int curr = 1;
        string ans = s.substr(0,1);
        for(int i = 1; i<s.size(); ++i) {
            if(s[i] == s[i-1]) {
                ++curr;
                if(curr < 3) {
                    ans.push_back(s[i]);
                }
            } else {
                curr = 1;
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};