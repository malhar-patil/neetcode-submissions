class Solution {
public:
    int minNum(int n, unordered_map<int, int>& memo){
        if(n == 0){
            return 0;
        }
        if(memo.contains(n)){
            return memo[n];
        }
        int least = INT_MAX;
        int temp = 0;

        for(int i=sqrt(n);i>=1; i--){
            temp = 0;
            temp = minNum(n-pow(i,2), memo)+1;
            least = min(least, temp);
        }
        memo[n] = least;
        return least;
    }
    int numSquares(int n) {
        unordered_map<int, int> memo;
        return minNum(n, memo);
    }
};