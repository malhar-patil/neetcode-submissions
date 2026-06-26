class Solution {
public:
    int maxNum(int n, vector<int>& memo){
        if(n<2){
            return n;
        }

        if(memo[n] != -1){
            return memo[n];
        }

        int res = 0;
        for(int i=1;i<n;i++){
            int a = i;
            int b = maxNum(n-a, memo);
            int tempMax = max(a*b, i*(n-i));
            res = max(res, tempMax);
        }
        memo[n] = res;
        return res;
    }
    int integerBreak(int n) {
        vector<int>memo(n+1, -1);
        return maxNum(n, memo);
    }
};