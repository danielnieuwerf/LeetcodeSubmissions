class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int ans = 0;
        int pos = 0;
        for(auto num: nums) {
            pos += num;
            if(pos == 0)
                ++ans;
        }
        return ans;
    }
};