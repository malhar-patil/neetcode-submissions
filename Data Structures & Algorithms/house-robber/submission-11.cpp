class Solution {
public:
    unordered_map<int, int> memo;

    int dfs(int index, vector<int>&nums){
        if(index < 0){
            return 0;
        }

        if(memo.contains(index)){
            return memo[index];
        }
        int res = nums[index] + max(dfs(index-2, nums), dfs(index-3, nums));
        memo[index] = res;
        return res;
    }
    int rob(vector<int>& nums) {
        return max(dfs(nums.size()-1, nums), dfs(nums.size()-2, nums));
        
    }
};
