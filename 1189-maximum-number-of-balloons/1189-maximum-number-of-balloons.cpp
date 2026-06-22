class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mp;
        for(auto c: text)
            ++mp[c];
        int min = INT_MAX;
        const auto vals = {'b','a','n'};
        const auto vals2 = {'l','o'};
        for(auto c: vals) {
            min = std::min(min, mp[c]);
        }
        for(auto c: vals2) {
            min = std::min(min, mp[c]/2);
        }
        return min == INT_MAX ? 0 : min;
    }
};