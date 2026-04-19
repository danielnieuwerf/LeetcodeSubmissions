class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();
        int l = 0;
        int r = 1;
        while(l<n1 && r<n2) {
            if (nums2[r] >= nums1[l]) {
                ++r;
                ans = max(ans, r-l-1);
            } else {
                ++l;
                ++r;
            }
        }
        return ans;
    }
};