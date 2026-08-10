class Solution {
public:
    double recursion(double x, int n){
        if(n==0){
            return 1;
        }
        double res = recursion(x, n/2);
        if(n%2==0){
            return res*res;
        }
        else{
            return x * res * res;
        }
    }
    double myPow(double x, int n) {
        if(n<0){
            return (double)1/recursion(x, -n);
        }
        return recursion(x, n);
    }
};
