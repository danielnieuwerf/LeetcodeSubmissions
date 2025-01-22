class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>> ans(n, vector<int>(m,-1));
        vector<int> current;
        for(int i = 0; i<n; ++i)
            for(int j = 0; j<m; ++j) {
                if(isWater[i][j] == 1)
                {
                    current.push_back(i*m + j);
                    ans[i][j] = 0;
                }
            }
        if(current.empty())
            current.push_back(0);

        int currentLevel = 0;
        while(!current.empty()) {
            vector<int> nextLevel;
            for(auto index: current) {
                int i = index/m, j = index%m;
                if(ans[i][j] > 0) continue;
                ans[i][j] = currentLevel;
                if(i<n-1 && ans[i+1][j] == -1)
                    nextLevel.push_back((i+1)*m+j);
                if(i>0 && ans[i-1][j] == -1)
                    nextLevel.push_back((i-1)*m+j);
                if(j<m-1 && ans[i][j+1] == -1)
                    nextLevel.push_back(i*m+j+1);
                if(j>0 && ans[i][j-1] == -1)
                    nextLevel.push_back(i*m+j-1);
            }
            ++currentLevel;
            current = nextLevel;
        }

        return ans;
    }
};