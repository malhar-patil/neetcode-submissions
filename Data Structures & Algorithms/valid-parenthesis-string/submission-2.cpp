class Solution {
public:
    bool checkValidString(string s) {
        stack<int> op;
        stack<int> st;

        for(int i=0;i<s.length();i++){
            if(s[i] == '('){
                op.push(i);
            }
            else if(s[i] == '*'){
                st.push(i);
            }
            else{
                if(op.empty() && st.empty()){
                    return false;
                }
                if(!op.empty()){
                    op.pop();
                    continue;
                }
                if(!st.empty()){
                    st.pop();
                    continue;
                }
            }
        }

        while(!op.empty() && !st.empty()){
            if(st.top() < op.top()){
                return false;
            }
            st.pop();
            op.pop();
        }

        if(op.empty()){
            return true;
        }
        return false;
    }
};
