class Solution {
public:
    bool isValid(char i, char j){
        if(i=='(' && j==')' || i=='{' && j=='}' || i=='[' && j==']'){
            return true;
        }
        return false;
    }
    bool isValid(string s) {
        stack<char> st;

        for(int i=0;i<s.length();i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
            }
            else{
                if(!st.empty() && isValid(st.top(), s[i])){
                    st.pop();
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
