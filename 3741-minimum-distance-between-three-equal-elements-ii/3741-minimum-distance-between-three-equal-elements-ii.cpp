class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        if(n<3) {
            return -1;
        }
        unordered_map<int,int> mp;
        for(auto num: nums) {
            ++mp[num];
        }
        int ans = INT_MAX;
        for(int i = 0; i<n-2; ++i) {
            if(mp[nums[i]] < 3) continue;
            for(int j = i+1; j<n-1 && j-i<ans; ++j) {
                if (nums[i] == nums[j]) {
                    for(int k = j+1;k<n; ++k) {
                        if (nums[j] == nums[k]) {
                            ans = min(ans,2*(k-i));
                            if (ans == 4) return 4;
                            break;
                        }
                    }
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};