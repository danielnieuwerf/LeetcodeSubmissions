class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            int left = nums[i];
            int right = left;
            while(i<n-1 && nums[i+1] == nums[i] + 1) {
                ++i;
                ++right;
            }
            if(left == right)
                ans.push_back(to_string(left));
            else
                ans.push_back(to_string(left)+"->"+to_string(right));
        }
        return ans;
    }
};