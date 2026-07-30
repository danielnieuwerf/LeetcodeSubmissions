class Solution {
public:
    int minimumPushes(string word) {
        vector<int> counts(26,0);
        for(auto c: word) {
            counts[c-'a']++;
        }
        erase(counts, 0);
        sort(counts.begin(),counts.end());
        int pushes = 0;
        int val = 1;
        int keysUsed = 0;
        for (auto it = counts.rbegin(); it != counts.rend(); ++it) {
            pushes += (*it)*val;
            ++keysUsed;
            if(keysUsed == 8) {
                keysUsed = 0;
                ++val;
            }
        }
        return pushes;
    }
};