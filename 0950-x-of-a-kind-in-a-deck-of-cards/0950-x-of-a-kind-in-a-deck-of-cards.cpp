class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int> mp;
        for(auto num: deck) {
            ++mp[num];
        }
        int gcd = mp[deck[0]];
        for(auto p: mp) {
            gcd = __gcd(gcd, p.second);
        }
        return gcd != 1;
    }
};