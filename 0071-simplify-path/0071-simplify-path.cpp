class Solution {
public:
    string simplifyPath(string path) {
        vector<string> p;
        string curr = "";
        int n = path.size();
        for(int i = 1; i<n; ++i) {
            if(path[i] == '.') {
                if(!curr.empty()) {
                    curr += ".";
                } else if(i < n-2 && path[i+1] == '.' && path[i+2] == '/') {
                    if(!p.empty())
                        p.pop_back();
                    i += 2;
                } else if(i < n-2 && path[i+1] == '.' && path[i+2] == '.') {
                    curr += "...";
                    i += 2;
                } else if(i == n-2 && path[n-1] == '.') {
                    if(!p.empty())
                        p.pop_back();
                } else if (i<n-1 && path[i+1] == '.') {
                    curr += "..";
                    i += 1;
                } else if(i < n -1 && path[i+1] != '/') {
                    curr += ".";
                }
            }
            else if(path[i] == '/') {
                if(!curr.empty()) {
                    p.push_back(curr);
                    curr = "";
                }
            }
            else {
                curr += path[i];
            }
        }
        if(!curr.empty() && curr != "..") {
            p.push_back(curr);
        }
        string ans = "";
        for(auto str: p)
        {
            ans += "/";
            ans += str;
        }
        return ans.empty() ? "/" : ans;
    }
};