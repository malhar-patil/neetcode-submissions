class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int money = 0;
        int l = 0;

        for(int r = 1; r < prices.size(); r++){
            money = max(money, prices[r] - prices[l]);
            if((prices[r] < prices[l])){
                l = r;
            }
        }
        return money;
    }
};
