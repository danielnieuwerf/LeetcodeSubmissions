class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_set<int> s;
        for(auto num: nums)
            s.insert(num);
        int n = nums.size();
        int prefix = nums[0];
        for(int i = 1; i<n; ++i) {
            if(nums[i] != nums[i-1] + 1)
                break;
            prefix += nums[i];
        }
        for(int num = prefix; num <= prefix + n; ++num) {
            if(!s.contains(num))
                return num;
        }
        return -1;
    }
};