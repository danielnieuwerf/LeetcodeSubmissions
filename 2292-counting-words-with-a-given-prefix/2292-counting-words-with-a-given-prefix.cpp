class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        for(auto& word: words)
            if(auto pos = word.find(pref); pos == 0)
                ++ans;
        return ans;
    }
};