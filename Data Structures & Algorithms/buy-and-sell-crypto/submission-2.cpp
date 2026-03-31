class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0;
        int r=1;
        int profit=0;
        while(r<prices.size()){
            profit=max(profit,prices[r]-prices[l]);
            if(prices[r]<prices[l]){
                l=r;
            }
            r++;
        }
        return profit;
    }
};
