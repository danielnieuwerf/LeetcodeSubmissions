class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        mp1[node1] = 0;
        auto curr = node1;
        auto currDistance = 1;
        while(1) {
            auto next = edges[curr];
            if(next == -1 || mp1.find(next) != mp1.end())
                break;
            mp1[next] = currDistance;
            ++currDistance;
            curr = next;
        }
        mp2[node2] = 0;
        curr = node2;
        currDistance = 1;
        while(1) {
            auto next = edges[curr];
            if(next == -1 || mp2.find(next) != mp2.end())
                break;
            mp2[next] = currDistance;
            ++currDistance;
            curr = next;
        }

        int ans = -1;
        int closestDistance = INT_MAX;
        for(int i = 0; i<edges.size(); ++i) {
            if(mp1.find(i) != mp1.end() && mp2.find(i) != mp2.end()) {
                if(closestDistance > max(mp1[i], mp2[i])) {
                    closestDistance = max(mp1[i], mp2[i]);
                    ans = i;
                }
            }
        }
        return ans;
    }
};