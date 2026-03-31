class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int ans=0;
        int a=0,b=0;
        for(int i=0;i<tokens.size();i++){
            string s = tokens[i];
            if(s=="+"){
                a = (st.top()); st.pop();
                b = (st.top()); st.pop();
                st.push(a+b);
            }
            else if(s=="-"){
                a = (st.top()); st.pop();
                b = (st.top()); st.pop();
                st.push(b-a);
            }
            else if(s=="*"){
                a = (st.top()); st.pop();
                b = (st.top()); st.pop();
                st.push(a*b);
            }
            else if(s=="/"){
                a = (st.top()); st.pop();
                b = (st.top()); st.pop();
                st.push(b/a);
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
