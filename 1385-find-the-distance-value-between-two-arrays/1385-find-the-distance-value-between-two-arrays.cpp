class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int ans = 0;
        for(auto num: arr1) {
            bool found = false;
            for(auto num2: arr2) {
                if(abs(num-num2) <= d) {
                    found = true;
                    break;
                }
            }
            if(!found) {
                ++ans;
            }
        }
        return ans;
    }
};