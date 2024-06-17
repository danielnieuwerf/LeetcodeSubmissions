class Solution {
public:
    bool judgeSquareSum(int c) {
        if (c%4==3)
            return false;
        
        int left = 0, right = sqrt(c);
        while(left <= right){
            auto temp = (long) left*left + (long) right*right;
            if(temp == c) return true;
            if(temp > c)
                --right;    
            else if(temp < c)
                ++left;        
        }
        
        return false;
    }
};