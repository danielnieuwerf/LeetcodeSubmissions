class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxNum = 1;
        int dupe = -1;
        for(auto num: nums) {
            auto x = ++mp[num];
            if(x>1) {
                dupe = num;
            }
            maxNum = max(maxNum, num);
        }
        int firstNotOccuringNum = -1;
        for(int i = 1; i<1e5; ++i) {
            if(mp.find(i) == mp.end()) {
                firstNotOccuringNum = i;
                break;
            }
        }
        return {dupe, firstNotOccuringNum};
    }
};