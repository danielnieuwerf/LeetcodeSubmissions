class Solution {
    unordered_map<char,int> mp{};
    
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        createRequirements(words2);
        
        vector<string> ans;
        for(string& s: words1)
            if(wordMeetsRequirement(s))
                ans.push_back(s);
        
        return ans;
    }
    
    void createRequirements(vector<string>& words2)
    {
        for(string& s: words2)
        {
            unordered_map<char,int> m{};
            for(char c: s)
                ++m[c];
            
            for(auto& p: m)
            {
                mp[p.first] = max(p.second, mp[p.first]);
            }
        }
    }
    
    bool wordMeetsRequirement(string& word)
    {
        unordered_map<char,int> m{};
        for(auto c : word)
            m[c]++;
        
        for(auto& p: mp)
        {
            if(m[p.first] < mp[p.first])
                return false;
        }
        return true;
    }
};