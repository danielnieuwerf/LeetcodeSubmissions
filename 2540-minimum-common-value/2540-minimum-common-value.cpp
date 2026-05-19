class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;

        int best = INT_MAX;
        for(auto num: nums1)
            ++mp[num];
        for(auto num: nums2) {
            if(mp.find(num) != mp.end())
                best = min(best, num);
        }
        
        return best == INT_MAX ? -1 : best;
    }
};