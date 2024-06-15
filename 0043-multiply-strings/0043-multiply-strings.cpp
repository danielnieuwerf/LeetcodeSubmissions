class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1[0] == '0' || num2[0] == '0')
            return "0";
        int n = num1.size();
        int m = num2.size();
        vector<int> memo(n+m,0);
        for(int i = 0; i<n; ++i) {
            for(int j = 0; j<m; ++j) {
                int x = (num1[i]-'0') * (num2[j]-'0');
                memo[i+j] += x;
            }
        }

        for(int i = n+m-1; i>0;--i) {
            int x = memo[i]%10;
            memo[i-1] += memo[i]/10;
            memo[i] = x;
        }
        
        string ans = "";
        for(int i = 0; i<n+m-1; ++i)
            ans += to_string(memo[i]);
        return ans;
    }
};