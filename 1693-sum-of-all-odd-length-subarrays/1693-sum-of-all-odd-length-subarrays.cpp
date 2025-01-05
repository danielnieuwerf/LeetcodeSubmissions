class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefixSum(n+1, 0);
        prefixSum[0] = arr[0];
        for(int i = 1; i<n; ++i)
            prefixSum[i] = prefixSum[i-1] + arr[i];

        int ans = 0;
        for(int start = 0; start<n; ++start)
        {
            int len = 1;
            while(start + len <= n) {
                ans += prefixSum[start+len-1];
                if(start != 0)
                    ans -= prefixSum[start-1];
                len += 2;
            }
        }
        return ans;
    }
};