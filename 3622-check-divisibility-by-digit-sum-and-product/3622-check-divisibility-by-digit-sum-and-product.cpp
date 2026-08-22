class Solution {
public:
    bool checkDivisibility(int n) {
        int val = digitSum(n)+productSum(n);
        return n%val == 0;
    }

    int digitSum(int n) {
        int ans = 0;
        while(n) {
            ans += n%10;
            n /= 10;
        }
        return ans;
    }

    int productSum(int n) {
        int ans = 1;
        while(n) {
            ans *= n%10;
            n /= 10;
        }
        return ans;
    }
};