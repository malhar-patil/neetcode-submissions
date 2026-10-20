class Solution {
public:
    int climbStairs(int n) {
        int a = 1;
        int b = 1;

        while(n-1 > 0){
            int ans = a+b;
            a = b;
            b = ans;
            n--;
        }

        return b;
    }
};
