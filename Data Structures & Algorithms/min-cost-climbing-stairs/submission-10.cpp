class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int s = cost[0];
        int e = cost[1];
        int index = 2;
        int res;
        while(index<cost.size()+1){
            if(index == cost.size()){
                e = min(s,e);
                index++;
                continue;
            }
            int temp = cost[index] + min(s,e);
            s = e;
            e = temp;
            index++;
        }
        return e;
    }
};