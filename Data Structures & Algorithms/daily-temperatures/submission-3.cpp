class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>results(temperatures.size(),0);
        stack<int> st;
        for(int i=0;i<temperatures.size();i++){
            if(st.empty() || temperatures[i] <= temperatures[st.top()]){
                st.push(i);
                continue;
            }
            while(!st.empty() && temperatures[i] > temperatures[st.top()]){
                results[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return results;
    }
};
