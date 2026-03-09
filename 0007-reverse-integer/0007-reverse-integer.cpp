class Solution {
public:
    int reverse(int x) {
        if(x == 0 || x == INT_MIN) {
            return 0;
        }
        vector<int> digits;
        while(x) {
            digits.push_back(x%10);
            x /= 10;
        }
        int ans = 0;
        for(auto it = digits.begin(); it != digits.end(); ++it) {
            if(ans > INT_MAX/10 || ans < INT_MIN/10) {
                return 0;
            }
            ans *= 10;
            ans += *it;
        }
        return ans;
    }
};