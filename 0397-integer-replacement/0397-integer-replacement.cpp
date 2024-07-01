class Solution {
    unordered_map<int,long> mp;
    
public:
    int integerReplacement(int n) {
        return integerReplacement((long) n);
    }
    
    long integerReplacement(long n) {
        if(n == 1) return 0;
        if(mp.find(n) != mp.end()) return mp[n];
        if(n%2 == 0) return mp[n] = (1 + integerReplacement(n/2));
        
        return mp[n] = (1 + min(integerReplacement(n+1), integerReplacement(n-1)));
    }
};