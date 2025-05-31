class Solution {
public:
    string winningPlayer(int x, int y, bool flag = true) {
        if(x>0 && y>3) {
            return winningPlayer(x-1, y-4, !flag);
        }
        return flag ? "Bob" : "Alice";
    }
};