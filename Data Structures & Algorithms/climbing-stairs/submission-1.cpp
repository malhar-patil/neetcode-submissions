class Solution {
public:
    int solve(int n, unordered_map<int,int>& m){
        if(n <= 2){
            return n;
        }
        if(m.find(n) != m.end()){
            return m[n];
        }
        int x = solve(n-1,m);
        int y = solve(n-2,m);
        m[n-1] = x;
        m[n-2] = y;
        return x+y;
    }
    int climbStairs(int n){
        unordered_map<int,int> m;
        return solve(n,m);
    }
};
