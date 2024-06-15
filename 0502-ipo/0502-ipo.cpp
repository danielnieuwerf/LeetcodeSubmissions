struct Task {
    int index;
    int profit;
    int capital;
};

class CompareProfit {
    public:
       bool operator()(Task a, Task b){
        return a.profit < b.profit;
      }
};

class CompareCapital {
    public:
       bool operator()(Task a, Task b){
        return a.capital > b.capital;
      }
};

using ProfitHeap = priority_queue<Task, vector<Task>, CompareProfit>;
using CapitalHeap = priority_queue<Task, vector<Task>, CompareCapital>;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        if(k==0) return w;

        ProfitHeap canDo;
        CapitalHeap cantDo;
        for(int i = 0; i<profits.size(); ++i) {
            if(w >= capital[i]) {
                canDo.push({i, profits[i], capital[i]});
            } else {
                cantDo.push({i, profits[i], capital[i]});
            }
        }

        while(k && !canDo.empty()) {
            // Do task at the top.
            auto task = canDo.top();
            w += task.profit;
            canDo.pop();
            --k;

            // Move any cantDo to canDo that we can now do.
            while(!cantDo.empty()) {
                auto t = cantDo.top();
                if(t.capital <= w) {
                    canDo.push(t);
                    cantDo.pop();
                } else break;
            }
        }

        return w;
    }
};