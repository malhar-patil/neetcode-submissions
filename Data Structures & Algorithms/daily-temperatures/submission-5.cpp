class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //monotonic stack
        stack<int> st; //store indexes
        vector<int> ans(temperatures.size(),0);

        for(int i=0;i<temperatures.size();i++){
            if(st.empty()){
                st.push(i);
                continue;
            }

            while(!st.empty() && temperatures[i] > temperatures[st.top()]){
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
        // 0 0 0 0 0 0 0
    }
};
