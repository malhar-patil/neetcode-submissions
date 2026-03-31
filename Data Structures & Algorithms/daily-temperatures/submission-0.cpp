class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(),0);
        stack<int> st;

        for(int i=0;i<temperatures.size();i++){
            if(st.empty()){
                st.push(i);
                continue;
            }

            if(temperatures[i]<=temperatures[st.top()]){
                st.push(i);
            }
            else{
                while(!st.empty() && temperatures[i]>temperatures[st.top()]){
                    int temp = st.top();
                    ans[temp] = i-temp;
                    st.pop();
                }
                st.push(i);
            }
        }
        return ans;
    }
};
