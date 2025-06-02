class Solution {
    int n = 0;

public:
    int candy(vector<int>& ratings) {
        n = ratings.size();
        vector<int> candy = vector<int>(n, 1);

        bool isDecreasing = true;
        for(int i = 1; i<n; ++i) {
            if(ratings[i]>=ratings[i-1]) {
                isDecreasing = false;
                break;
            }
        }

        if(isDecreasing) {
            for(int i = 0; i<n; ++i)
                candy[i] = n-i;
        }

        rec(ratings, candy);
        return accumulate(candy.begin(), candy.end(), 0);
    }

    void rec(vector<int>& ratings, vector<int>& candy) {
        bool changed = false;

        for(int i = 0; i<n; ++i) {
            if(i>0 && ratings[i-1]<ratings[i] && candy[i-1]>=candy[i]) {
                candy[i] = candy[i-1]+1;
                changed = true;
            }

            if(i<n-1 && ratings[i+1]<ratings[i] && candy[i+1]>=candy[i]) {
                candy[i] = candy[i+1]+1;
                changed = true;
            }
        }

        if(changed)
            rec(ratings, candy);
    }
};