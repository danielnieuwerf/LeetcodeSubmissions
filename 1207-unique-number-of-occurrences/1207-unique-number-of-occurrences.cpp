class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto num: arr) {
            ++mp[num];
        }
        unordered_set<int> counts;
        for(auto p: mp) {
            if(counts.contains(p.second)) {
                return false;
            }
            counts.insert(p.second);
        }
        return true;
    }
};