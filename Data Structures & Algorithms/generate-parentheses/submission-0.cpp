class Solution {
public:
    void solve(vector<string>& ans, string s,int n, int open,int close){
        if(close>open){
            return;
        }
        if(s.length()==2*n){
            if(open==close){
                ans.push_back(s);
            }
            return;
        }
        if(open<n){
            s.append("(");
            open++;
            solve(ans,s,n,open,close);
            s.erase(s.length()-1);
            open--;
        }
        if(close<n){
            s.append(")");
            close++;
            solve(ans,s,n,open,close);
            s.erase(s.length()-1);
            close--;
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        solve(ans,s,n,0,0);
        return ans;
    }
};
