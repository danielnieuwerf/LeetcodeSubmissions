class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(auto num: nums) {
            if(num > 9 && num < 100)
                ++ans;
            else if(num > 999 && num < 10000)
                ++ans;
            else if(num == 100000)
                ++ans;
        }
        return ans;
    }
};