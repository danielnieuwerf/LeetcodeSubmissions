class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int ans = accumulate(cost.begin(), cost.end(), 0);
        int n = cost.size();
        for(int i = 0; i<n/3; ++i) {
            ans -= cost[n-3- 3*i];
        }
        return ans;
    }
};