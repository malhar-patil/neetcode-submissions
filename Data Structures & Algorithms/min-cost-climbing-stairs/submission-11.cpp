class Solution {
public:
    int minCost(int goal, vector<int>& cost, unordered_map<int,int>& m){
        if(goal <= 1){
            return cost[goal];
        }
        if(m.find(goal) != m.end()){
            return m[goal];
        }
        
        m[goal] = min(cost[goal]+minCost(goal-1, cost, m), cost[goal]+minCost(goal-2, cost, m));
        return m[goal];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        int goal = cost.size()-1;
        unordered_map<int,int> m;
        return minCost(goal, cost, m);
    }
};
