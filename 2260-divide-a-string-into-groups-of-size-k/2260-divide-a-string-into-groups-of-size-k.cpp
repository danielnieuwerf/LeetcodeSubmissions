class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int i = 0;
        int n = s.size();
        while(i < n) {
            if(i+k<=n) {
                ans.push_back(s.substr(i, k));
                i += k;
            } else {
                auto len = n-i;
                string curr = s.substr(i, n-i);
                while(len < k) {
                    ++len;
                    curr += fill;
                }
                ans.push_back(curr);
                break;
            }
        }
        return ans;
    }
};