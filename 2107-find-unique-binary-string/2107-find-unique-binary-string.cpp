class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_map<string,int> mp;

        for(auto s: nums)
            ++mp[s];

        for(int i=0; i<pow(2,n); ++i)
            if(mp.find(to_binary(i,n)) == mp.end())
                return to_binary(i,n);

        return ":(";
    }

    string to_binary(int x, int n) {
        string ans;
        for(int i = 0; i<n; ++i) {
            if(x%2) {
                ans += "1";
            } else {
                ans += "0";
            }
            x = x>>1;
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};