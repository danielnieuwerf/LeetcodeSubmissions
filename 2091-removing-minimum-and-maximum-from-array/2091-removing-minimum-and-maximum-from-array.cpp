class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mi = min_element(nums.begin(), nums.end()) - nums.begin();
        int ma = max_element(nums.begin(), nums.end()) - nums.begin();
        int l = min(mi, ma);
        int r = max(mi, ma);
        return min({
            r + 1,
            n - l,
            l + 1 + n - r
        });
    }
};