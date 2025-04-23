class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int,int> mp;
        for(int i = 1; i<=n; ++i) {
            ++mp[sumOfDigits(i)];
        }

        int largestGroupSize = 0;
        for(auto p: mp) {
            largestGroupSize = max(largestGroupSize, p.second);
        }
        int ans = 0;
        for(auto p: mp) {
            if(p.second == largestGroupSize) {
                ++ans;
            }
        }
        return ans;
    }

    int sumOfDigits(int n) {
        int ans = 0;
        while(n) {
            ans += n%10;
            n /= 10;
        }
        return ans;
    }
};