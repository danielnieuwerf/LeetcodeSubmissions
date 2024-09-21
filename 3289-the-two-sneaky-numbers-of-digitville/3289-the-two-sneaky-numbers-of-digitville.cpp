class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> mp;
        for(auto num: nums) {
            ++mp[num];
            if(mp[num] > 1) {
                ans.push_back(num);
                if(ans.size() > 1)
                    return ans;
            }
        }
        return ans;
    }
};