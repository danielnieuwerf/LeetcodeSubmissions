class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> prefixSum(n+1, 0);
        for(auto& shift: shifts) {
            int start = shift[0], end = shift[1], direction = shift[2] == 1 ? 1 : -1;
            prefixSum[start] += direction;
            prefixSum[end+1] -= direction;
        }

        int currentShift = 0;        
        for(int i = 0; i<n; ++i) {
            currentShift += prefixSum[i];
            int shift = ((s[i]-'a' + currentShift)%26 + 26)%26;
            s[i] = 'a' + shift;
        }
        return s;
    }
};