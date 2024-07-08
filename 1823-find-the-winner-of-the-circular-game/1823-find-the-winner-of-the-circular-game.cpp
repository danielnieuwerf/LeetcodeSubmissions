class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> players(n, 0);
        for(int i = 1; i<=n; ++i)
            players[i-1] = i;
        int index = 0;
        int remaining = n;
        while(remaining > 1) {
            index += (k-1);
            index %= remaining;
            players.erase(players.begin() + index);
            --remaining;
            index %= remaining;
        }
        
        return players[0];
    }
};