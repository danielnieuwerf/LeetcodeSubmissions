class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> prefixSum(52,0);
        for(auto range: ranges) {
            ++prefixSum[range[0]];
            --prefixSum[range[1]+1];
        }
        int current = 0;
        for(int i = 0; i<51; ++i) {
            current += prefixSum[i];
            if(current < 1 && i >= left && i <= right)
                return false;
        }
        return true;
    }
};