class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if((k%10)%2 == 0) {
            return -1;
        }
        if(k == 1) {
            return 1;
        }
        int digits = 2;
        int start = 11;
        if(k<12) {
           start = 11;
           digits = 2;
        } else if(k<112) {
            start = 111;
            digits = 3;
        } else if(k<1112) {
            start = 1111;
            digits = 4;
        } else if(k<11112) {
            start = 11111;
            digits = 5;
        } else if(k<=111112) {
            start = 111111;
            digits = 6;
        }
        int first = start % k;
        // 11 = 1 * 10 + 1 (mod k) = X
        // 111 = 11 * 10 + 1 (mod k) = 10 * X + 1 (mod k)
        // next = 10*first+1 mod k
        for(int i = 0; i<k; ++i) {
            if (first == 0) {
                return digits + i;
            }
            // cout << first << endl;
            first = (10*first+1)%k;
        }
        return -1;

    }
};