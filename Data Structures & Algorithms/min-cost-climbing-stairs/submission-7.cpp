class Solution {
public:
    int solve(int index, vector<int>& cost, unordered_map<int,int>&m){
        if(index <= 1){
            m[index] = cost[index];
            return m[index];
        }

        if(m.find(index) != m.end()){
            if(index>=cost.size()){
                return m[index];
            }
            return cost[index] + m[index];
        }
        // 2 step
        int x = solve(index-2, cost, m);
        // 1 step
        int y = solve(index-1, cost, m);

        m[index] = min(x,y);
        if(index>=cost.size()){
            return m[index];
        }
        return cost[index] + m[index];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        unordered_map<int,int> minCostToN;
        return solve(cost.size()+1, cost, minCostToN);
    }
};
