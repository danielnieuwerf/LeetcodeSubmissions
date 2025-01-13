class Solution {
public:
    int minimumLength(string s) {
        vector<int> frequencies(26,0);
        for(auto c: s) {
            ++frequencies[c-'a'];
        }
        int ans = 0;
        for(auto freq: frequencies)
        {
            if(freq == 0) continue;
            if(freq % 2 == 1)
                ++ans;
            else
                ans += 2;
        }
        return ans;
    }
};