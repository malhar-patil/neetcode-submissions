class Solution {
public:
    bool isValid(char ch, stack<char>& st){
        if(!st.empty() && ((st.top()=='(' && ch==')') || (st.top()=='[' && ch==']') || (st.top()=='{' && ch=='}'))){
            return true;
        }
        return false;
    }
    bool isValid(string s) {
        if(s[0]==')' || s[0]==']' || s[0]=='}'){
            return false;
        }

        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                st.push(s[i]);
            }
            else if(isValid(s[i],st)){
                st.pop();
            }
            else{
                return false;
            }
        }

        if(st.empty()){
            return true;
        }
        return false;

    }
};
