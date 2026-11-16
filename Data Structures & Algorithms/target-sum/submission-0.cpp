class Solution {
public:
    vector<vector<int>>memo;
    int dfs(int index, vector<int>& nums,int total, int sum, int target){
        if(index >= nums.size()){
            if(sum == target){
                return 1;
            }
            return 0;
        }
        if(sum < 0 && memo[index][(2*total+1) + sum] != INT_MIN){
            return memo[index][(2*total+1) + sum];
        }
        if(sum >= 0 && memo[index][sum] != INT_MIN){
            return memo[index][sum];
        }

        //plus
        int plus = dfs(index+1, nums, total,sum + nums[index], target);
        //minus
        int minus = dfs(index+1, nums, total,sum - nums[index], target);

        int res = plus+minus;

        if(sum >= 0){
            return memo[index][sum] = res;
        }
        return memo[index][(2*total+1) + sum] = res;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        for(int i=0;i<nums.size();i++){
            total += nums[i];
        }
        memo.assign(nums.size()+1, vector<int>(2*total+1, INT_MIN));
        return dfs(0, nums,total,0, target);
    }
};