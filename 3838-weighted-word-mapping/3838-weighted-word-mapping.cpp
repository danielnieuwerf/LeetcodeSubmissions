class Solution {
    unordered_map<char,int> mp;
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        for(int i = 0; i<26; ++i)
            mp['a'+i] = weights[i];
        string ans;
        for(auto word: words) {
            ans += 'z' - weight(word);
        }
        return ans;
    }

    int weight(string word) {
        int ans = 0;
        for(auto c: word) {
            ans += mp[c];
        }
        return ans % 26;
    }
};