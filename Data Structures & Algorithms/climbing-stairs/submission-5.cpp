class Solution {
public:
    int climbStairs(int n) {
        int a = 0;
        int b = 1;

        while(n-1 >= 0){
            int temp = a+b;
            a = b;
            b = temp;
            n--;
        }

        return b;
    }
};
