class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto num: nums)
            ++mp[num];
        int start = k;
        while(1) {
            if(!mp.contains(start))
                return start;
            start += k;
        }

        return -1;
    }
};