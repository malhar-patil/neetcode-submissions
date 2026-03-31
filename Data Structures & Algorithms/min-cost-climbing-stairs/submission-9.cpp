class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> arr(cost.size()+1,0);
        arr[0] = cost[0]; arr[1] = cost[1];
        for(int i=2;i<arr.size();i++){
            if(i>=cost.size()){
                arr[i] = min(arr[i-1],arr[i-2]);
                continue;
            }
            arr[i] = cost[i] + min(arr[i-1],arr[i-2]);
        }
        return arr[arr.size()-1];
    }
};