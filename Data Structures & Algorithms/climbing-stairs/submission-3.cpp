class Solution {
public:
    int count(int n, unordered_map<int,int>& m){
        if(n == 0){
            return 1;
        }
        if(n < 0){
            return 0;
        }
        
        if(m.find(n) != m.end()){
            return m[n];
        }

        m[n] = count(n-1, m) + count(n-2, m);
        return m[n];
    }
    int climbStairs(int n) {
        unordered_map<int,int> m;
        return count(n, m);
    }
};
