class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        long long ans = 0;
        int odd = 0, even = 1;
        int prefix = 0;
        for (int x : arr) {
            prefix = (prefix + x) % 2;
            if (prefix) {
                ans += even;
                ++odd;
            } else {
                ans += odd;
                ++even;
            }
            ans %= MOD;
        }

        return ans;
    }
};