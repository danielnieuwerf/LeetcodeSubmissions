class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int cnt = 0;
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            int lcm = nums[i];
            if(lcm == k) {
                ++cnt;
            }
            if(lcm > k) {
                continue;
            }
            int j = i+1;
            while(j<n) {
                lcm = std::lcm(lcm, nums[j]);
                if(lcm == k) {
                    ++cnt;
                }
                if(lcm > k) {
                    break;
                }
                ++j;
            }
        }
        return cnt;
    }
};