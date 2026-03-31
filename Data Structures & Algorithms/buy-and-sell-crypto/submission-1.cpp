class Solution {
public:
    int maxProfit(vector<int>& prices) {
        stack<int>st;
        int maxProfit=0;
        st.push(prices[0]);

        for(int i=1;i<prices.size();i++){
            if(prices[i]<st.top()){
                st.push(prices[i]);
                continue;
            }
            int tempProfit=prices[i]-st.top();
            maxProfit = max(maxProfit, tempProfit);
        }

        return maxProfit;
    }
};
