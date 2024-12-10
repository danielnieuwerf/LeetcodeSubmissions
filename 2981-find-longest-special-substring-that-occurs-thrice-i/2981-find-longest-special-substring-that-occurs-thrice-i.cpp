class Solution {
public:
    int maximumLength(string s) {
        // Binary search on lengths 1 ... n
        int n = s.size();
        int ans = -1;
        int left = 1;
        int right = n;
        while(left <= right) {
            int mid = (left+right)/2;
            // check substrs of length mid
            int appearances = 0;
            unordered_map<string, int> mpOfCounts;
            for(int start = 0; start<n; ++start) {
                if(start+mid > n) break;
                if(!isSpecialString(s.substr(start, mid))) continue;
                appearances = max(appearances, ++mpOfCounts[s.substr(start, mid)]);
            }
            if(appearances >= 3) {
                ans = max(ans, mid);
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
    
    bool isSpecialString(string s) {
        char firstChar = s[0];
        for(auto c: s)
            if(c != firstChar)
                return false;
        return true;
    }
};