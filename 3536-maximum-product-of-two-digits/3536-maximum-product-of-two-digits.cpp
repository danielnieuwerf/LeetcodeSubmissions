class Solution {
public:
    int maxProduct(int n) {
        int max1 = -1;
        int max2 = -1;
        while(n) {
            auto next = n%10;
            if(next>max1) {
                max2 = max1;
                max1 = next;
            } else if(next > max2) {
                max2 = next;
            }
            n /= 10;
        }
        return max1*max2;
    }
};