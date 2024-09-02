class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = accumulate(chalk.begin(),chalk.end(), 0LL);
        k %= sum;
        long long curr = 0;
        for(int i = 0; i<chalk.size(); ++i) {
            curr += (long long) chalk[i];
            if(curr > k)
                return i;
        }
        return 0;
    }
};