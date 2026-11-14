class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int lowest = INT_MAX;
        int n = nums.size();
        for(int len = l; len<=r; ++len) {
            for(int i = 0;i<n-len+1;++i) {
                int sum = accumulate(nums.begin()+i,nums.begin()+i+len,0);
                if(sum>0) {
                    if(sum == 1)
                        return 1;
                    lowest = min(lowest, sum);
                }
            }
        }
        return lowest == INT_MAX ? -1 : lowest;
    }
};