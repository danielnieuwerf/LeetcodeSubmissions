class Solution {
    int n;
    vector<int> _prices;
    int dp[100002][3][2];
public:
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        _prices = prices;
        memset(dp, -1, sizeof dp);
        return rec(0,0,0);
    }
    
    int rec(int i, int transactions, int ownStock) {
        if(i == n || transactions>=2) return 0;
        if(dp[i][transactions][ownStock] != -1) return dp[i][transactions][ownStock];
        
        int profit = 0;
        if(ownStock) {
            int doNothing = rec(i+1,transactions,1);
            int sell = _prices[i] + rec(i+1, transactions+1, 0);
            profit = max(doNothing, sell);
        } else {
            int doNothing = rec(i+1,transactions,0);
            int buy = -_prices[i] + rec(i+1, transactions, 1);
            profit = max(doNothing, buy);
        }
        return dp[i][transactions][ownStock] = profit;
    }
};