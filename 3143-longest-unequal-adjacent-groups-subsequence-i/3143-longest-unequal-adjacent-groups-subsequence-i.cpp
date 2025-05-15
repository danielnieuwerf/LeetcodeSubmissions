class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans;
        int start = groups[0];
        ans.push_back(words[0]);
        for(int i = 1; i< words.size(); ++i) {
            if(groups[i] != start) {
                ans.push_back(words[i]);
                start = groups[i];
            }
        }
        return ans;
    }
};