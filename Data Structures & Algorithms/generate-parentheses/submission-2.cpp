class Solution {
public:
    void dfs(int open, int close, int n, stack<char> st, string&temp, vector<string>& res){
        cout<<temp<<" "<<st.empty()<<endl;
        if(open + close == 2*n && st.empty()){
            res.push_back(temp);
        }
        if(open > n || close > n){
            return;
        }

        //add (
        temp.push_back('(');
        st.push('(');
        dfs(open+1, close, n, st, temp, res);
        temp.pop_back();
        st.pop();

        //add )

        if(!st.empty()){
            temp.push_back(')');
            st.pop();
            dfs(open, close+1, n, st, temp, res);
            temp.pop_back();
        }

        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string temp = "";
        int open = 0;
        int close = 0;
        stack<char> st;
        int index = 0;
        
        dfs(open, close, n, st, temp, res);
        return res;

    }
};
