class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gasTotal = 0;
        int costTotal = 0;

        for(int i=0;i<gas.size();i++){
            gasTotal += gas[i];
            costTotal += cost[i];
        }

        if(costTotal > gasTotal){
            return -1;
        }

        int total = 0;
        int ans = 0;
        for(int i=0;i<gas.size();i++){
            total = total + gas[i] - cost[i];
            if(total < 0){
                total = 0;
                ans = (i+1)%gas.size();
            }
        }
        return ans;
    }
};
