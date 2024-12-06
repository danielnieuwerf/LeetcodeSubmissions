class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_map<int,int> ban;
        for(auto num: banned)
            ++ban[num];
        int currentSum = 0;
        int nums = 0;
        for(int i = 1; i<=n; ++i) {
            if(ban.find(i) == ban.end()) {
                currentSum += i;
                if(currentSum <= maxSum) {
                    ++nums;
                } else break;
            }
        }
        return nums;
    }
};