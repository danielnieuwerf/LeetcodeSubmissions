class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> mp{};
        for(auto edge: edges) {
            if(++mp[edge[0]] > 1) return edge[0];
            if(++mp[edge[1]] > 1) return edge[1];
        }
        
        return -1;
    }
};