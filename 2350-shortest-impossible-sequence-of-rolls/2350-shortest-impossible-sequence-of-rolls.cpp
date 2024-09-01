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
        auto indexes = getIndexesOfFirstValueAfterStart(-1);
        while(find(indexes.begin(), indexes.end(), -1) == indexes.end()) {
            indexes = getIndexesOfFirstValueAfterStart(*max_element(indexes.begin(), indexes.end()));            
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
        for(auto index: _mp[val])
            if(index > start)
                return index;
        return -1;
    }
};