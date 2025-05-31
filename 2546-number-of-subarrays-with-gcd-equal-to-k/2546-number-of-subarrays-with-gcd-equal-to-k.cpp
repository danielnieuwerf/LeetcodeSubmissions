class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int cnt = 0;
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            int gcd = nums[i];
            if(gcd == k) {
                ++cnt;
            }
            if(gcd < k) {
                continue;
            }
            int j = i+1;
            while(j<n) {
                gcd = __gcd(gcd,nums[j]);
                if(gcd == k) {
                    ++cnt;
                }
                if(gcd < k) {
                    break;
                }
                ++j;
            }
        }
        return cnt;
    }
};