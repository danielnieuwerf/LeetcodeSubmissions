class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int highest = 0;
        int current = 0;
        for(auto g: gain)
        {
            current += g;
            highest = max(highest, current);
        }

        return highest;
    }
};