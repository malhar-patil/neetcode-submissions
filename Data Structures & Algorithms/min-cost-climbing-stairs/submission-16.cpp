class Solution {
public:
    unordered_map<int, int> memo;
    int dfs(vector<int>& cost, int n){
        if(n == 0 || n == 1){
            return cost[n];
        }
        if(memo.contains(n)){
            return memo[n];
        }
        int a = dfs(cost, n-1);
        int b = dfs(cost, n-2);

        if(n < cost.size()){
            int res = min(a, b) + cost[n];
            memo[n] = res;
            return res;
        }
        memo[n] = min(a, b);
        return min(a, b);
        
    }
    int minCostClimbingStairs(vector<int>& cost) {
        return dfs(cost, cost.size());
    }
};
