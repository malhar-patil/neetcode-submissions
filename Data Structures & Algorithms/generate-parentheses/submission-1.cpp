class Solution {
public:
    vector<string> res;
    void dfs(int n, string temp, int open, int close){
        if(temp.length() >= n*2){
            res.push_back(temp);
            return;
        }
        if(open < n){
            dfs(n, temp+'(', open+1, close);
        }

        if(close < open){
            dfs(n, temp+')', open, close+1);
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        string temp = "";
        stack<char> st;
        int open = 0;
        int close = 0;
        dfs(n, temp, open, close);
        return res;
    }
};
