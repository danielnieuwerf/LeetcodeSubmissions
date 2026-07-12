class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> a = arr;

        sort(arr.begin(), arr.end());
        unordered_map<int,int> mp{};

        int rank = 1;
        for(auto& num: arr)
            if(mp.find(num) == mp.end())
                mp[num] = rank++;


        vector<int> ans;
        ans.reserve(a.size());
        for(int num: a)
            ans.push_back(mp[num]);

        return ans;
    }
};