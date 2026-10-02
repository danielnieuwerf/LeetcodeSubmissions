class Solution {
public:
    vector<string>ans;  
    vector<string> generateParenthesis(int n) {
        generate(0,0,"",n);
        return ans;
    }
    
    void generate(int l, int r, string k, int len){
        if(k.length()==2*len){
            ans.push_back(k);
            return;
        }
        
        if(l<len)
            generate(l+1,r,k+"(",len);
        if(r<l)
            generate(l, r+1, k+")", len);

    }
};