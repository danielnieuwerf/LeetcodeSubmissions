class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles;
        int fullBottles = 0;
        int emptyBottles = numBottles;
        while(1) {
            if(emptyBottles >= numExchange) {
                emptyBottles -= numExchange;
                ++fullBottles;
                ++numExchange;
            } else {
                if(fullBottles == 0)
                    break;
                ans += fullBottles;
                emptyBottles += fullBottles;
                fullBottles = 0;
            }
        }
        
        return ans;
    }
};