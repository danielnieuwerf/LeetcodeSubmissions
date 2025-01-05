class Solution {
    const int MOD = 1e9+7;
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        // prefix sum to quickly compute weights of each index.
        vector<int> prefixSum(n+1, 0);
        for(auto& request: requests) {
            ++prefixSum[request[0]];
            --prefixSum[request[1] + 1];
        }
        vector<int> weights(n, 0);
        int currentWeight = 0;
        for(int i = 0; i<n; ++i) {
            currentWeight += prefixSum[i];
            weights[i] = currentWeight;
        }
        sort(weights.begin(), weights.end());

        long ans = 0;
        for(int i = n - 1; i>-1; --i) {
            ans += (long) weights[i]*nums[i];
            ans %= MOD;
        }
        return ans;
    }
};