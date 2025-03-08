class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans = 100;
        for(int i = 0; i<=blocks.size()-k; ++i) {
            int numBlacks = 0;
            for(int j = 0; j<k; ++j)
                if(blocks[i+j]=='B')
                    ++numBlacks;
            ans = min(ans, k-numBlacks);
        }
        return ans;
    }
};