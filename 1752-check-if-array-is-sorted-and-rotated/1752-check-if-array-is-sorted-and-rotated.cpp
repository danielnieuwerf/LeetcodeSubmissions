class Solution {
public:
    bool check(vector<int>& nums) {
        auto numsSorted = nums;
        sort(numsSorted.begin(), numsSorted.end());
        if (numsSorted == nums)
            return true;
        
        int n = nums.size();
        int firstDecreasingIndex = -1;
        for(int i = 1; i<n; ++i) {
            if (nums[i] < nums[i-1]) {
                if(firstDecreasingIndex != -1)
                    return false;
                firstDecreasingIndex = i;
            }
        }
        auto test = vector<int>();
        for(int i = firstDecreasingIndex; i<n; ++i)
            test.push_back(nums[i]);
        for(int i = 0; i<firstDecreasingIndex; ++i)
            test.push_back(nums[i]);

        return test == numsSorted;
    }
};