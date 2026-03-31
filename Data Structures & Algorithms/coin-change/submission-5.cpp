class Solution {
public:
    bool isPossible = false;
    unordered_map<int, int> m;
    int solve(vector<int>& coins, int amount){
        if(m.find(amount) != m.end()){
            return m[amount];
        }
        if(amount == 0){
            isPossible = true;
            return 0;
        }
        if(amount<0){
            return INT_MAX/10;
        }
        int minRemaining = INT_MAX;
        for(int i=0;i<coins.size();i++){
            minRemaining = min(minRemaining, solve(coins, amount-coins[i]));
        }
        m[amount] = 1 + minRemaining;
        return m[amount];

    }
    int coinChange(vector<int>& coins, int amount){
        int res = solve(coins, amount);
        if(!isPossible){
            return -1;
        }
        return res;
    }
};
