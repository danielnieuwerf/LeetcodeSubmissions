class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for(auto op: operations) {
            op.contains("-") ? --x : ++x;
        }
        return x;
    }
};