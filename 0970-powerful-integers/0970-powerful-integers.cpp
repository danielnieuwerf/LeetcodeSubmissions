class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        set<int> s;
        for(int i=0;; ++i) {
            auto X = pow(x,i);
            for(int j = 0;; ++j) {
                int curr = X+pow(y,j); 
                if (curr > bound)
                    break;
                s.insert(curr);
                if(y == 1)
                    break;
            }
            if(X>bound || x == 1)
                break;
        }
        vector<int> ans;
        for(auto num: s) {
            ans.push_back(num);
        }
        return ans;
    }
};