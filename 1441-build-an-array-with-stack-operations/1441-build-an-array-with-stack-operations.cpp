class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans{};
        int current = 1;
        for(int& t:target){
            while(t>current){
                ans.push_back("Push");
                ans.push_back("Pop");
                ++current;
            }

            ans.push_back("Push");
            ++current;

        }
        return ans;
    }
};