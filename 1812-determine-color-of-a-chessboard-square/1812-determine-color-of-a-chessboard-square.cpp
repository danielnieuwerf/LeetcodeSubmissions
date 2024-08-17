class Solution {
public:
    bool squareIsWhite(string c) {
        return (1 + (int)(c[0]-'a') + c[1]%2)%2;
    }
};