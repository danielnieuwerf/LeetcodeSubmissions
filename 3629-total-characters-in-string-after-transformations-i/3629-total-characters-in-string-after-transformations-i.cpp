class Solution {
    const int MOD = 1e9+7;
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int> cnt(26,0);
        for(auto c: s)
            ++cnt[c-'a'];
        
        int ans = s.size();
        for(int i = 0; i<t; ++i) {
            ans += cnt[25];
            ans %= MOD;
            int temp = cnt[25] % MOD;
            for(int j = 25; j>0; --j)
                cnt[j] = cnt[j-1] % MOD;
            cnt[1] += temp;
            cnt[0] = temp;
        }
        return ans;
    }
};