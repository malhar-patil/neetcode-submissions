class Solution {
public:
    bool isValid(string s) {
        if(s.length()>0 && s[0]==')' || s[0]==']' || s[0]=='}'){
            return false;
        }
        stack<int>st;

        for(int i=0;i<s.length();i++){
            if((s[i]=='(' || s[i]=='[' || s[i]=='{')){
                st.push(s[i]);
                continue;
            }

            if(!st.empty() && ((s[i]==')' && st.top()=='(') || (s[i]==']' && st.top()=='[') || (s[i]=='}' && st.top()=='{'))){
                st.pop();
            }
            else{
                return false;
            }
        }
        if(st.empty()){return true;}
        return false;
    }
};
