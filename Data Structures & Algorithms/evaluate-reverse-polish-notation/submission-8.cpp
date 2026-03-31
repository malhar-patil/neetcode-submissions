class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_set<string> s;
        s.insert("+");s.insert("-");s.insert("/");s.insert("*");
        stack<int> st;
        for(int i=0;i<tokens.size();i++){
            if(s.find(tokens[i]) != s.end()){
                int x = (st.top()); st.pop();
                int y = (st.top()); st.pop();

                if(tokens[i] == "+"){st.push(x+y);}
                else if(tokens[i] == "-"){st.push(y-x);}
                else if(tokens[i] == "*"){st.push(x*y);}
                else {st.push(y/x);}
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
