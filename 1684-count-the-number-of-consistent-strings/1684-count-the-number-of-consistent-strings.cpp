class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> s;
        for(auto c: allowed)
            s.insert(c);
        auto count = 0;
        for(auto word: words) {
            bool consistent = true;
            for(auto c: word) {
                if(!s.contains(c)) {
                    consistent = false;
                    break;
                }
            }
            if(consistent)
                ++count;
        }
        return count;
    }
};