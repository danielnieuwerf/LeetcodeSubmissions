class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = -1;

        if (k == 1) {
            unordered_map<int, int> freq;
            for (int x : nums)
                freq[x]++;

            for (int x : nums)
                if (freq[x] == 1)
                    ans = max(ans, x);

            return ans;
        }

        if (k == n)
            return *max_element(nums.begin(), nums.end());

        bool flag = true;
        for (int i = 1; i < n; i++)
            if (nums[i] == nums[0])
                flag = false;

        if (flag)
            ans = max(ans, nums[0]);

        flag = true;
        for (int i = 0; i < n - 1; i++)
            if (nums[i] == nums[n - 1])
                flag = false;

        if (flag)
            ans = max(ans, nums[n - 1]);

        return ans;
    }
};