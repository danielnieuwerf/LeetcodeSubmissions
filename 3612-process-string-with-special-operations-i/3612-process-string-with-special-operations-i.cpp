class Solution {
public:
    string processStr(string s) {
        string ans = "";
        for(auto c: s) {
            if(c == '*') {
                if(!ans.empty()) {
                    ans = ans.substr(0, ans.size()-1);
                }
            } else if(c == '#') {
                ans += ans;
            } else if(c == '%') {
                reverse(ans.begin(), ans.end());
            } else {
                ans += c;
            }
        }
        return ans;
    }
};