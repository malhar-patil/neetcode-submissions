class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        dp[0] = 0;

        for(int i=1;i<dp.size();i++){
            int numCoins = INT_MAX;
            for(int j=0;j<coins.size();j++){
                if(i - coins[j] >= 0 && dp[i - coins[j]] != -1){
                    numCoins = min(numCoins, dp[i-coins[j]]+1);
                }
            }
            if(numCoins != INT_MAX){
                dp[i] = numCoins;
            }
        }
        // for(int i=0;i<dp.size();i++){
        //     cout<<dp[i]<<" ";
        // }
        return dp[dp.size()-1];
    }
};
