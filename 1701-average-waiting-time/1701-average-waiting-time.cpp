class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double totalWaitTime = 0.0;
        int n = 0;
        int time = 0;
        for(auto it=customers.begin(); it!=customers.end(); ++it) {
            ++n;
            time = max(time, it->at(0));
            totalWaitTime += (time + it->at(1) - it->at(0));
            time += it->at(1);
        }
        
        return totalWaitTime/n;
    }
};