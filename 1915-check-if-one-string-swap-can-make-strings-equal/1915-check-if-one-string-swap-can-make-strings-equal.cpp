class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> diffs;
        for(int i =0; i<s1.size(); ++i)
        {
            if(s1[i]!=s2[i])
                diffs.push_back(i);
            if(diffs.size()>2) 
                return false;
        }
        if(diffs.empty()) 
            return true;
        if(diffs.size() == 1) 
            return false;
        
        return s1[diffs[0]] == s2[diffs[1]] && s1[diffs[1]] == s2[diffs[0]];
    }
};