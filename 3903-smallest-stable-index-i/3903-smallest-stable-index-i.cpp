class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int curr = nums[0];
        int n = nums.size();
        for(int i = 0; i<n; ++i) {
            curr = max(curr,nums[i]);
            int x = *min_element(nums.begin()+i,nums.end());
            if(curr-x <= k)
                return i;
        }
        return -1;
    }
};