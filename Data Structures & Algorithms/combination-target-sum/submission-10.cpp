class Solution {
public:
    void dfs(int index, int sum, int& target, vector<int>& nums, vector<int>& temp, vector<vector<int>>& res){
        if(sum > target){
            return;
        }
        if(index >= nums.size()){
            if(sum == target){
                res.push_back(temp);
            }
            return;
        }
        temp.push_back(nums[index]);
        if(sum + nums[index] < target){
            //include
            dfs(index, sum+nums[index], target, nums, temp, res);
        }
        else{
            dfs(index+1, sum+nums[index], target, nums, temp, res);
        }
        //exclude
        temp.pop_back();
        dfs(index+1, sum, target, nums, temp, res);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int>temp;
        int sum = 0;
        dfs(0, sum, target, nums, temp, res);
        return res;
    }
};
