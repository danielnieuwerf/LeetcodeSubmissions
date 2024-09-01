class Solution {
    vector<int> _rolls;
    int _n;
    int _k;
    unordered_map<int,vector<int>> mp;  // value to sorted indexes the value appears.
public:
    int shortestSequence(vector<int>& rolls, int k) {
        _rolls = rolls;
        _n = rolls.size();
        _k = k;
        if(k==1) return _n+1;
        for(int i = 0; i<_n;++i) {
            mp[rolls[i]].push_back(i);
        }

        int ans = 1;
        auto indexes = getIndexesOfFirstValueAfterStart(-1);
        while(find(indexes.begin(), indexes.end(), -1) == indexes.end()) { // k*n
            
            vector<int> nextIndexes = getIndexesOfFirstValueAfterStart(*max_element(indexes.begin(), indexes.end()));
            
            indexes = nextIndexes;
            ++ans;
        }
        
        return ans;
    }
    
    vector<int> getIndexesOfFirstValueAfterStart(int start) {
        vector<int> ans;
        for(int i = 1; i<=_k; ++i) {
            ans.push_back(indexOfValAfterStart(start, i));
        }
        return ans;
    }
    
    int indexOfValAfterStart(int start, int val) {
        for(auto index: mp[val])
            if(index > start)
                return index;
        return -1;
    }
};