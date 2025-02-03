class Solution {
    enum State {
        UP,
        DOWN,
        SIDE,
    } state;

public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int best = 1;
        int curr = 1;
        int last = nums[0];
        for(int i = 1; i< nums.size(); ++i) {
            if(nums[i]>last) {
                if(state == UP) {
                    ++curr;
                } else {
                    state = UP;
                    curr = 2;
                }
            } else if(nums[i] == last) {
                state = SIDE;
                curr = 1;
            } else {
                if(state == DOWN) {
                    ++curr;
                } else {
                    state = DOWN;
                    curr = 2;
                }
            }

            last = nums[i];
            best = max(best, curr);
        }

        return best;
    }
};