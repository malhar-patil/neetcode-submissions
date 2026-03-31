class Solution {
public:
    bool check(stack<char>& st, char ch){
        if((ch==')' && st.top()=='(') || (ch==']' && st.top()=='[') || (ch=='}' && st.top()=='{')){
            st.pop();
            return true;
        }
        return false;
    }
    bool isValid(string s) {
        if(s[0] == ')' || s[0] == ']' || s[0] == '}'){
            return false;
        }
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
            }
            else{
                if(!st.empty() && check(st, s[i])){
                    continue;
                }
                else{
                    return false;
                }
            }
        }
        if(st.empty()){
            return true;
        }
        return false;


    }
};
