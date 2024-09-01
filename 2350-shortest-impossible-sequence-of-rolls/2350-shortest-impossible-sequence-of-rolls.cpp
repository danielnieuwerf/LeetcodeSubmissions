class Solution {
    int _k;
    unordered_map<int,vector<int>> _mp;  // value to sorted indexes the value appears.
public:
    int shortestSequence(vector<int>& rolls, int k) {
        _k = k;
        if(k==1) return rolls.size()+1;
        for(int i = 0; i<rolls.size();++i) {
            _mp[rolls[i]].push_back(i);
        }

        int ans = 1;
        auto index = getIndexAfterStart(-1);
        while(index != -1) {
            index = getIndexAfterStart(index);      
            ++ans;
        }
        
        return ans;
    }
    
    int getIndexAfterStart(int start) {
        int ans = 0;
        for(int i = 1; i<=_k; ++i) {
            if(auto val = indexOfValAfterStart(start, i)) {
                if(val == -1) return -1;
                ans = max(ans, val);
            }
        }
        return ans;
    }
    
    int indexOfValAfterStart(int start, int val) {
        for(auto index: _mp[val])
            if(index > start)
                return index;
        return -1;
    }
};