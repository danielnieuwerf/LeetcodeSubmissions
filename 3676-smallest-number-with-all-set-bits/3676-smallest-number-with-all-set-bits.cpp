class Solution {
public:
    int smallestNumber(int n) {
        int x = 1;
        while(pow(2,x)<=n) {
            ++x;
        }
        return pow(2,x) - 1;
    }
};