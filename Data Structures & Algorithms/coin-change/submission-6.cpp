class Solution {
public:
    int dfs(vector<int>& coins, unordered_map<int, int>& m, int amount){
        if(m.find(amount) != m.end()){
            return m[amount];
        }

        if(amount == 0){
            return 0;
        }

        if(amount < 0){
            return -1;
        }

        int numCoins = INT_MAX;
        for(int i=0;i<coins.size();i++){
            int ret = dfs(coins, m, amount - coins[i]);
            if(ret != -1){
                numCoins = min(numCoins, ret+1);   
            }
        }

        if(numCoins == INT_MAX){
            m[amount] = -1;
            return m[amount];
        }
        m[amount] = numCoins;
        return m[amount];
    }
    int coinChange(vector<int>& coins, int amount){
        unordered_map<int, int> m;
        return dfs(coins, m, amount);
    }
};
