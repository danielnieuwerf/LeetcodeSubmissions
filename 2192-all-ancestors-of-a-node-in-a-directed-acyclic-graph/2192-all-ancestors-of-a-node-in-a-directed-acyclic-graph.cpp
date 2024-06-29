class Solution {
    vector<vector<int>> dp;
    vector<bool> computed;
    unordered_map<int, vector<int>> mp;
    
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        dp = vector<vector<int>>(n, vector<int>(1, -1));
        computed = vector<bool>(n, false);
        for(auto edge: edges)
            mp[edge[1]].push_back(edge[0]);
        
        vector<vector<int>> ans = vector<vector<int>>(n, vector<int>());
        for(int i = 0; i<n; ++i)
            ans[i] = ancestors(i);
        return ans;
    }
    
    vector<int> ancestors(int i) {
        if(computed[i]) return dp[i];
        computed[i] = true;
        
        set<int> a;
        for(auto edge: mp[i]) {
            a.insert(edge);
            for(auto ancestor: ancestors(edge))
                a.insert(ancestor);
        }
        
        vector<int> ans;
        for(auto ancestor: a)
            ans.push_back(ancestor);
    
        return dp[i] = ans;
    }    
};