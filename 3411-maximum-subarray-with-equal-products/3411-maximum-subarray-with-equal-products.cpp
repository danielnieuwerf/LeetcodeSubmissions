class Solution {
public:
    int maxLength(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i<n; ++i) {
            int prod = nums[i];
            int gcd = prod;
            int lcm = prod;
            for(int j = i+1; j<n; ++j) {
                prod *= nums[j];
                gcd = __gcd(gcd, nums[j]);
                lcm = std::lcm(lcm, nums[j]);
                if(prod != gcd * lcm) {
                    break;
                }
                ans = max(ans, j-i+1);
            }
        }
        return ans;
    }
};