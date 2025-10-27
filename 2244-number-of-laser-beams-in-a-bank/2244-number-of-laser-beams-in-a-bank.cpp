class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        int curr = 0;
        for(int i = 0; i<bank.size(); ++i) {
            auto now = std::ranges::count(bank[i], '1');
            if(now != 0) {
                ans += curr*now;
                curr = now;
            }
        }

        return ans;
    }
};