class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int> mp;
        for(auto num: arr) {
            ++mp[num];
        }
        for (auto it = mp.rbegin(); it != mp.rend(); ++it) {
            if (it->first == it->second) {
                return it->first;
            }
        }
        return -1;
    }
};