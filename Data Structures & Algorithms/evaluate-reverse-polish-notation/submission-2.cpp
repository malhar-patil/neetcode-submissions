class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        int num1=0;
        int num2=0;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="*" && tokens[i]!="/"){
                st.push(stoi(tokens[i]));
                continue;
            }

            if(tokens[i]=="+"){
                num1=st.top();
                st.pop();
                num2=st.top();
                st.pop();
                st.push(num1+num2);    
            }
            else if(tokens[i]=="-"){
                num1=st.top();
                st.pop();
                num2=st.top();
                st.pop();
                st.push(num2-num1);      
            }
            else if(tokens[i]=="*"){
                num1=st.top();
                st.pop();
                num2=st.top();
                st.pop();
                st.push(num1*num2);    
            }
            else if(tokens[i]=="/"){
                num1=st.top();
                st.pop();
                num2=st.top();
                st.pop();
                st.push(num2/num1);    
            }
        }
        return st.top();
    }
};
