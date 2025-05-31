class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        for(int i = 0; i<n-1; ++i) {
            for(int j = i+1; j<n; ++j) {
                if(__gcd(firstDigit(nums[i]), nums[j]%10) == 1) {
                    ++cnt;
                }
            }
        }
        return cnt;
    }

    int firstDigit(int num) {
        while(num >= 10) {
            num /= 10;
        }
        return num;
    }
};