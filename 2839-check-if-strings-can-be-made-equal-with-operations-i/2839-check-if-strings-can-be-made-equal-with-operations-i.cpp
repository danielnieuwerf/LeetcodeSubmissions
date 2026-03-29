class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        bool a1 = (s1[0] == s2[0]) || (s1[0] == s2[2] && s1[2] == s2[0]);
        bool a2 = (s1[1] == s2[1]) || (s1[1] == s2[3] && s1[3] == s2[1]);
        bool a3 = (s1[2] == s2[2]) || (s1[0] == s2[2] && s1[2] == s2[0]);
        bool a4 = (s1[3] == s2[3]) || (s1[1] == s2[3] && s1[3] == s2[1]);
        return (a1 && a3) && (a2 && a4);
    }
};