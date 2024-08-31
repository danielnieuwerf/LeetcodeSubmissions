class Solution {
    class DamageComparator {
        public:
            bool operator() (pair<int,int> p, pair<int,int> q) {
                int killQThenPCost = q.first*q.second + p.second*(q.first+p.first);
                int killPThenQCost = p.first*p.second + q.second*(q.first+p.first);
                return killPThenQCost > killQThenPCost;
            }
    };

public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        long long damageTaken = 0;
        long long damagePerSec = accumulate(damage.begin(), damage.end(), 0);
        priority_queue<pair<int,int>, vector<pair<int,int>>, DamageComparator> pq;
        for(int i = 0; i<damage.size(); ++i) {
            int hitsToKill = (health[i]/power) + (health[i]%power == 0 ? 0 : 1);
            pq.push(make_pair(hitsToKill, damage[i]));
        }
        while(!pq.empty()) {
            // cout << pq.top().first << " " << pq.top().second << " " << damagePerSec << endl;
            auto t = pq.top();
            damageTaken += t.first*damagePerSec;
            damagePerSec -= t.second;
            pq.pop();
        }

        return damageTaken;
    }
};