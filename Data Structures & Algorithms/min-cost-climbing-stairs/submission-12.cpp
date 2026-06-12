class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> arr;
        arr.push_back(cost[0]);
        arr.push_back(cost[1]);

        
        for(int i=2;i<cost.size();i++){
            arr.push_back(min(cost[i] + arr[i-1], cost[i] + arr[i-2]));
        }
        return min(arr[arr.size()-1], arr[arr.size()-2]);
    }
};
