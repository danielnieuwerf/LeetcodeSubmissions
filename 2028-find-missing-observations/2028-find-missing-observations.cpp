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
        vector<int> ans;
        ans.reserve(n);
        while(n) {
            if(total >= n+5) {
                ans.push_back(6);
                total -= 6;
            } else if(total >= n+4) {
                ans.push_back(5);
                total -= 5;
            } else if(total >= n+3) {
                ans.push_back(4);
                total -= 4;
            } else if(total >= n+2) {
                ans.push_back(3);
                total -= 3;
            } else if(total >= n+1) {
                ans.push_back(2);
                total -= 2;
            } else if(total >= n) {
                ans.push_back(1);
                total -= 1;
            }
            
            --n;
        }
        return ans;
    }
};