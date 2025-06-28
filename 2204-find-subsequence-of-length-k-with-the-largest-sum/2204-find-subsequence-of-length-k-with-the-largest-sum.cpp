class Solution {
    using PAIR = pair<int,int>;
    using VECTOR = vector<PAIR>;
    class Compare {
    public:
        bool operator() (PAIR p, PAIR q)
        {
            return p.second < q.second;
        }
    };
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<PAIR, VECTOR, Compare> pq;
        for(int i = 0; i<nums.size(); ++i) {
            pq.push(make_pair(i, nums[i]));
        }
        vector<int> indexes;
        while(!pq.empty() && k--) {
            indexes.push_back(pq.top().first);
            pq.pop();
        }
        sort(indexes.begin(), indexes.end());
        vector<int> ans;
        for(auto index: indexes) {
            ans.push_back(nums[index]);
        }
        return ans;
    }
};