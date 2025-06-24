class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        int n = nums.size();
        for(int i = 0; i<n; ++i) {
            bool isKDistant = false;
            for(int j = max(0, i-k); j<min(n, i+k+1); ++j) {
                if(nums[j] == key) {
                    isKDistant = true;
                    break;
                }
            }
            if(isKDistant) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};