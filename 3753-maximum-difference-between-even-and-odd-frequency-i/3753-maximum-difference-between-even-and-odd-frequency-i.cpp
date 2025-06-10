class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int> mp;
        for(auto val: s) {
            ++mp[val];
        }
        int ans = 0;
        int maxEven = 0;
        int minEven = 100;
        int maxOdd = 0;
        int minOdd = 100;
        for(auto p: mp) {
            if(p.second % 2 == 0) {
                maxEven = max(maxEven, p.second);
                minEven = min(minEven, p.second);
            } else {
                maxOdd = max(maxOdd, p.second);
                minOdd = min(minOdd, p.second);
            }
        }
        return max(minOdd - maxEven, maxOdd-minEven);
    }
};