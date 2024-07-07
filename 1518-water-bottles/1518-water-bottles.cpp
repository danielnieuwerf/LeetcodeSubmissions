class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        int fullBottles = numBottles;
        int emptyBottles = 0;
        while(fullBottles) {
            ans += fullBottles;
            emptyBottles += fullBottles;
            fullBottles = emptyBottles/numExchange;
            emptyBottles %= numExchange;
        }
        
        return ans;
    }
};