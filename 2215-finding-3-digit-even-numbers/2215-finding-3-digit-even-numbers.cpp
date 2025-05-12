class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> digitCounts(10, 0);
        for(auto digit: digits)
            ++digitCounts[digit];
        set<int> s;
        for(int i = 1; i<=9; ++i)
            for(int j = 0; j<=9; ++j)
                for(int k = 0; k<=8; k += 2) {
                    auto val = i*100 + j * 10 + k;
                    vector<int> counts(10, 0);
                    ++counts[i];
                    ++counts[j];
                    ++counts[k];
                    bool isPossible = true;
                    for(int l = 0; l<=9; ++l)
                        if(counts[l] > digitCounts[l]) {
                            isPossible = false;
                            break;
                        }
                    if(isPossible) {
                        s.insert(val);
                    }
                }
        vector<int> ans;
        for(auto val: s)
            ans.push_back(val);
        return ans;
    }
};