class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int total = (m+n)*mean;
        int sum = accumulate(rolls.begin(), rolls.end(), 0);
        int missingTotal = total - sum;
        int minTotal = n;
        int maxTotal = 6 *n;
        if(missingTotal< minTotal || missingTotal>maxTotal)
            return {};
        return generatePermutation(missingTotal, n);
    }
    
    vector<int> generatePermutation(int total, int n) {
        vector<int> ans = vector<int>(n, 1);
        int i = 0;
        while(n) {
            if(total >= n+5) {
                ans[i] = 6;
                total -= 6;
            } else if(total >= n+4) {
                ans[i] = 5;
                total -= 5;
            } else if(total >= n+3) {
                ans[i] = 4;
                total -= 4;
            } else if(total >= n+2) {
                ans[i] = 3;
                total -= 3;
            } else if(total >= n+1) {
                ans[i] = 2;
                total -= 2;
            } else if(total >= n) {
                break;
            }
            
            --n;
            ++i;
        }
        return ans;
    }
};