class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=1;i<m;i++)
            for(int j=0;j<n;j++)
                if(matrix[i][j]==1)
                    matrix[i][j]=matrix[i-1][j]+1;

        int ans=0;
        for(auto itr:matrix)
        {
            sort(itr.begin(),itr.end());
    
            for(int k=n-1,w=1;k>=0 && itr[k]>0;k--,w++)
            {   
                int area=itr[k]*w;
                ans=max(ans,area);
            }
        }
        return ans;
    }
};