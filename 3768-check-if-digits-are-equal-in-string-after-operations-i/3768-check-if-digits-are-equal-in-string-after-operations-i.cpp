class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.size();
        while(n > 2) {
            string newStr;
            for(int i = 0; i<n-1; ++i) {
                newStr += to_string(((int)(s[i] - '0') + (int)(s[i+1] - '0'))%10);
            }
            s = newStr;
            --n;
        }
        return s[0] == s[1];
    }
};