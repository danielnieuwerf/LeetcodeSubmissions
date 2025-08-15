class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 1 || n == 4) {
            return true;
        }
        long curr = 4;
        while(curr < n){
            curr *= 4;
            if(curr == n)
                return true;
        }
        return false;
    }
};