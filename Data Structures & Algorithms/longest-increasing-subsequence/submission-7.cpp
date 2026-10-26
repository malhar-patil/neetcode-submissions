class Solution {
public:
    unordered_map<int, int> memo;
    int dfs(int index, int num, vector<int>& nums){
        if(index >= nums.size()){
            return 0;
        }

        if(memo.contains(index)){
            return memo[index];
        }

        int longest = 0;
        for(int i=index;i<nums.size();i++){
            if(nums[i] > num){
                longest = max(longest, 1 + dfs(i+1, nums[i], nums));
            }
        }

        memo[index] = longest;
        return longest;
    }
    int lengthOfLIS(vector<int>& nums) {
        int index = 0;
        return dfs(index, INT_MIN, nums); 
    }
};
