class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(auto it = nums.begin(); it<nums.end(); ++it) {
            if(mp.find(target-*it) != mp.end())
                return {static_cast<int>(distance(nums.begin(), it)), mp[target-*it]};
            mp[*it] = distance(nums.begin(), it);
        }
        return {-1, -1};
    }
};