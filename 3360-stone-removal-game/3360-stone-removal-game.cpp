class Solution {
public:
    bool canAliceWin(int n) {
        bool a = true;
        int curr = 10;
        while(n>=curr) {
            n -= curr;
            a = !a;
            --curr;
        }
        return !a;
    }
};