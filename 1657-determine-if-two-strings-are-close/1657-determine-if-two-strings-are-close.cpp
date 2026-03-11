class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) {
            return false;
        }
        vector<int> v1(26,0);
        vector<int> v2(26,0);
        for(auto c: word1) {
            ++v1[(int)(c-'a')];
        }
        for(auto c: word2) {
            ++v2[(int)(c-'a')];
        }
        for(int i = 0; i<26; ++i) {
            if((v1[i] == 0 && v2[i] != 0)||(v2[i] == 0 && v1[i] != 0)) {
                return false;
            }
        }
        // v1.erase(remove(v1.begin(), v1.end(), 0), v1.end());
        // v2.erase(remove(v2.begin(), v2.end(), 0), v2.end());
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        return v1 == v2;
    }
};