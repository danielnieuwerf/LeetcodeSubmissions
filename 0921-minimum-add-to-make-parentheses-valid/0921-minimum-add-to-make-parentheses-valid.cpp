class Solution {
public:
    int minAddToMakeValid(string S) {
        process(S);
        return S.size();
    }
    
    void process(string& s){
        // recursively remove all "()" from s
        int n = s.size();
        if(n<2)
            return;
        
        bool flag = true;   // flags whether there are "()" to remove
        
        string ss{};
        for(int i=0;i<n-1;++i){
            if(s[i]=='(' && s[i+1]==')'){
                ++i;
                flag = false;
            }
            else{
                ss+=s[i];
            }
        }
        if(!(s[n-1]==')' && s[n-2]=='('))
            ss+=s[n-1];
        
        if(flag)
            return;
        
        // Else remove them and call process again
        s = ss;
        process(s);
    }
};