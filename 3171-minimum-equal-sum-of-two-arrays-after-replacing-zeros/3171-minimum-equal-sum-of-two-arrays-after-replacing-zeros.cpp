class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long  x1 = 0;
        int count1 = 0;
        long long  x2 = 0;
        int count2 = 0;
        for(auto num: nums1) {
            x1 += (long long) num;
            if(num == 0)
                ++count1;
        }
        for(auto num: nums2) {
            x2 += (long long) num;
            if(num == 0)
                ++count2;
        }

        if(count1 == 0 && x2+count2>x1) {
            return -1;
        }
        if(count2 == 0 && x1+count1>x2) {
            return -1;
        }

        return max(x1 + count1, x2 + count2);
    }
};