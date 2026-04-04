class Solution {
public:
    int getSum(int n){
        int sum = 0;
        while(n>0){
            int temp = n%10;
            sum += abs(pow(temp,2));
            n=n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> visited;
        visited.insert(n);
        while(n != 1){
            n = getSum(n);
            if(visited.find(n) != visited.end()){
                break;
            }
            visited.insert(n);
        }
        if(n==1){
            return true;
        }
        return false;
    }
};
