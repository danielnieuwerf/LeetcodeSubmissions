class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        unordered_map<string,int> mp;
        int n = s.size();
        for(int i = 0; i<n-9; ++i) {
            auto x = ++mp[s.substr(i,10)];
            if(x == 2) {
                ans.push_back(s.substr(i,10));
            }
        }
        return ans;
    }
};