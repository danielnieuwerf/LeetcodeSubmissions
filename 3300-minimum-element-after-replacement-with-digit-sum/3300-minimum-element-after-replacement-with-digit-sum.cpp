class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
        for(int num: nums) {
            ans = min(ans, sumOfDigits(num));
        }
        return ans;
    }

    int sumOfDigits(int n) {
        int ans = 0;
        while(n) {
            ans += n%10;
            n /= 10;
        }
        return ans;
    }
};