class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxNum = *max_element(nums.begin(), nums.end());
        long long ans = 0;
        int n = nums.size();
        
        int l = 0;
        int r = 0;
        int curr = nums[0] == maxNum ? 1 : 0;
        while(l<=r) {
            if(curr<k) {
                if(r >= n-1)
                    break;
                ++r;
                if(nums[r] == maxNum) {
                    ++curr;
                }
            } else if(curr == k) {
                ans += n-r;
                if(l==r) {
                    ++l;
                    ++r;
                    if(nums[l-1] == maxNum) {
                        --curr;
                    }
                    if(l<n && nums[l] == maxNum) {
                        ++curr;
                    }
                    continue;
                }
                ++l;
                if(nums[l-1] == maxNum) {
                    --curr;
                }
            }
        }
        return ans;
    }
};