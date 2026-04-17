class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = INT_MAX;

        for (int i = 0; i < nums.size(); ++i) {
            if (mp.count(nums[i])) {
                ans = min(ans, i - mp[nums[i]]);
            }

            int num = reverseNum(nums[i]);
            mp[num] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }

    int reverseNum(int x) {
        int res = 0;
        while (x > 0) {
            res *= 10;
            res += (x % 10);
            x /= 10;
        }
        return res;
    }
};