class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int> a1;
        vector<int> a2;
        unordered_set<int> s1;
        unordered_set<int> s2;
        for(auto num: nums1) {
            s1.insert(num);
        }
        for(auto num: nums2) {
            s2.insert(num);
        }
        for(auto num: s1) {
            if(!s2.contains(num)) {
                a1.push_back(num);
            }
        }
        for(auto num: s2) {
            if(!s1.contains(num)) {
                a2.push_back(num);
            }
        }
        return {a1, a2};
    }
};