class Solution {
    int n;
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        n = nums.size();
        int l = 1;
        int r = n;
        if(!exists(n,target,nums)) return 0;

        int best = n;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(exists(mid, target, nums)){
                r = mid -1;
                best = min(best, mid);
            }
            else
                l = mid+1;
        }

        return best;
    }

    bool exists(int len, int target, vector<int>& nums)
    {
        int val = 0;
        for(int i = 0;i<len;++i)
            val += nums[i];
        if(val>=target) return true;

        for(int i = len;i<n;++i)
        {
            val -= nums[i-len];
            val += nums[i];
            if(val>=target) return true;
        }
        return false;
    }
};