class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int pivotCount = 0;
        vector<int> ans;
        vector<int> after;
        for(auto num: nums) {
            if(num < pivot)
                ans.push_back(num);
            else if(num == pivot)
                ++pivotCount;
            else
                after.push_back(num);
        }
        for(int i = 0; i<pivotCount; ++i)
            ans.push_back(pivot);
        for(auto num: after)
            ans.push_back(num);
        return ans;
    }
};