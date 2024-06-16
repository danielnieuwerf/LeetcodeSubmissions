class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        int best = 1;
        string ans = s.substr(0,1);

        for(int i = 1; i<n-1; ++i) // for each centre size 1
        {
            int curr = 1;
            int j = 1;
            while(i-j>=0 && i+j<n) {
                if(s[i-j] != s[i+j]) break;
                curr += 2;
                ++j;
            }
            if(curr > best) {
                best = curr;
                ans = s.substr(i-curr/2, curr);
            }
        }
        
        for(int i = 1; i<n; ++i) // for each centre size 2
        {
            if(s[i] != s[i-1]) continue;

            int curr = 2;
            int j = 1;
            while(i-1-j>=0 && i+j<n) {
                if(s[i-1-j] != s[i+j]) break;
                curr += 2;
                ++j;
            }
            if(curr > best) {
                best = curr;
                ans = s.substr(i-curr/2, curr);
            }
        }

        return ans;
    }
};