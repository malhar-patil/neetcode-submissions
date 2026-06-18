class Solution {
public:
    map<pair<int,int>, int> memo;

    int dfs(int index, int num, vector<int>& nums){
        if(index >= nums.size()) return 0;
        
        if(memo.count({index, num})) return memo[{index, num}];
        
        int len = 0;
        for(int i = index; i < nums.size(); i++){
            if(nums[i] > num){
                len = max(len, dfs(i+1, nums[i], nums) + 1);
            }
        }
        return memo[{index, num}] = len;
    }

    int lengthOfLIS(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            res = max(res, dfs(i+1, nums[i], nums)+1);
        }
        return res;
    }
};