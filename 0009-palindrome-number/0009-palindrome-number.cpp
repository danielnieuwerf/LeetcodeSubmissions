class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) {
            return false;
        }
        if (x<10) {
            return true;
        }
        vector<int> digits;
        while(x) {
            digits.push_back(x%10);
            x /= 10;
        }
        int n = digits.size();
        for(int i=0; i<n/2; ++i) {
            if(digits[i] != digits[n-1-i]) {
                return false;
            }
        }
        return true;
    }
};