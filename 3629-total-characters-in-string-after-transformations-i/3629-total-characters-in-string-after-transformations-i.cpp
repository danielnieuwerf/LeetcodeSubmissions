class Solution {
    const int MOD = 1e9+7;
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int> counts(26,0);
        for(auto c: s)
            ++counts[c-'a'];
        int ans = s.size();
        while(t--) {
            ans = (ans + counts[25] % MOD) % MOD;
            int z = counts[25] % MOD;
            for(int j = 25; j>0; --j)
                counts[j] = counts[j-1] % MOD;
            counts[1] += z;
            counts[0] = z;
        }
        return ans;
    }
};