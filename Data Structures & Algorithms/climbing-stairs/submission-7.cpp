class Solution {
public:
    unordered_map<int, int> memo;
    int dfs(int n){
        if(n == 0){
            return 1;
        }

        if(n < 0){
            return 0;
        }

        if(memo.contains(n)){
            return memo[n];
        }

        int res = dfs(n-1) + dfs(n-2);
        memo[n] = res;

        return res;
    }
    int climbStairs(int n) {
        return dfs(n);
    }
};
