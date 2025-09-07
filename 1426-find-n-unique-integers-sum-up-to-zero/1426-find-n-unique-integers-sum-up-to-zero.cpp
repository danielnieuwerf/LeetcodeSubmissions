class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        if(n%2 == 1) {
            ans.push_back(0);
            --n;
        }
        int curr = 1;
        while(n) {
            ans.push_back(curr);
            curr *= -1;
            --n;
            if(curr > 0) {
                ++curr;
            }
        }

        return ans;
    }
};