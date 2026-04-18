class Solution {
    bool isOp(string& s)
    {
        return s == "-" || s == "+" || s =="/" || s=="*";
    }

public:
    int evalRPN(vector<string>& tokens) {
        stack<long> st;
        for(auto& token: tokens)
        {
            if(isOp(token))
            {
                long t = st.top();
                st.pop();
                long t2 = st.top();
                st.pop();
                long result = 0;
                if(token == "-")
                    result = t2 - t;
                else if(token == "+")
                    result = t2 + t;
                else if(token == "/") 
                    result = t2 / t;
                else if(token == "*")
                    result = t2 * t;
                st.push(result);
            }
            else
            {
                st.push(stoi(token));
            }
        }

        return (int) st.top();
    }
};