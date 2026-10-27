class Solution {
public:
    vector<vector<int>> memo;
    bool dfs(int index, int sum, int half, vector<int>&nums){
        if(index >= nums.size()){
            if(sum == half){
                return true;
            }
            return false;
        }
        if(sum > half){
            return false;
        }

        if(memo[index][sum] != -1){
            return memo[index][sum];
        }

        bool res = dfs(index+1, sum + nums[index], half, nums) || dfs(index+1, sum, half, nums);
        memo[index][sum] = res;
        return res;
    }
    bool canPartition(vector<int>& nums) {
        int total = 0 ;
        for(int i=0;i<nums.size();i++){
            total += nums[i];
        }

        int half = total/2;
        int sum = 0;

        if(total % 2 != 0){
            return false;
        }
        memo.assign(nums.size(), vector<int>(half+1, -1));
        return dfs(0, sum, half, nums);        
    }
};
