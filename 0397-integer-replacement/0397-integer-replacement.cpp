class Solution {
    unordered_map<int,int> mp;
    
public:
    int integerReplacement(int n) {
        if(n == INT_MAX) 
            return 32;
        if(n == 1) 
            return 0;
        if(mp.find(n) != mp.end()) 
            return mp[n];
        if(n%2 == 0) 
            return mp[n] = (1 + integerReplacement(n/2));
        return mp[n] = (1 + min(integerReplacement(n+1), integerReplacement(n-1)));    
    }
};