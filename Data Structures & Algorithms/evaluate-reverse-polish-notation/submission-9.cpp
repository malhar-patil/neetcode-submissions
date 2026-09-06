class Solution {
public:
    bool isOperator(string s){
        if(s == "+" || s == "-" || s == "*" || s == "/"){
            return true;
        }
        return false;
    }
    int evalRPN(vector<string>& tokens) {
        int res = 0;
        stack<string> st;

        for(int i=0;i<tokens.size();i++){
            if(isOperator(tokens[i])){
                int temp = 0;
                int b = stoi(st.top()); st.pop();
                int a = stoi(st.top()); st.pop(); 
                if(tokens[i] == "+"){
                    st.push(to_string(a+b));
                }
                else if(tokens[i] == "-"){
                    st.push(to_string(a-b));
                }
                else if(tokens[i] == "*"){
                    st.push(to_string(a*b));
                }
                else{
                    st.push(to_string(a/b));
                }
            }
            else{
                st.push(tokens[i]);
            }
        }
            return stoi(st.top());
    }
};
