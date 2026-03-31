class Solution {
public:
    bool isValidPair(char ch, stack<char>&st){
        if(!st.empty() && ((ch==')' && st.top()=='(') || (ch==']' && st.top()=='[') || (ch=='}' && st.top()=='{'))){
            st.pop();
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
            else{
                if(!isValidPair(s[i],st)){
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
