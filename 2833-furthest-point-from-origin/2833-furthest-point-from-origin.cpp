class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        set<int> pos = {0};
        int n = moves.size();
        for(int i = 0; i<n; ++i) {
            set<int> newPos;
            for(auto val: pos) {
                if(moves[i] == 'L') {
                    newPos.insert(val-1);
                } else if(moves[i]=='R') {
                    newPos.insert(val+1);
                } else {
                    newPos.insert(val+1);
                    newPos.insert(val-1);
                }
            }
            pos = newPos;
        }
        return max(abs(*max_element(pos.begin(),pos.end())), abs(*min_element(pos.begin(),pos.end())));
    }
};