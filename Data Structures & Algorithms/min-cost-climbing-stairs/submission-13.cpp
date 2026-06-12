class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int a = cost[0];
        int b = cost[1];
        int temp = INT_MAX;

        int size = cost.size();

        for(int i=2;i<cost.size();i++){
            int temp = min(cost[i] + a, cost[i] + b);
            a = b;
            b = temp;
        }

        return min(a,b);
    }
};
