class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
         int n = nums.size();
         auto _nums = nums;
         sort(_nums.begin(), _nums.end());
         vector<int> ans(n,0);
         for(int i =0; i<n; ++i) {
            auto it = std::find_if(_nums.begin(), _nums.end(),
                [val = nums[i]](int x) { return x >= val; });
            ans[i] = it - _nums.begin();
         }
         return ans;
    }
};