class Solution {
public:
    bool checkString(string s) {
        bool hasB = false;
        for(auto c: s) {
            if(c=='a' && hasB)
                return false;
            if(c=='b')
                hasB = true;
        }
        return true;
    }
};