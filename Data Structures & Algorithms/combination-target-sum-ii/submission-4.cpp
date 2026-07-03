class Solution {
public:
    void dfs(int index, vector<int>& nums, int& target,vector<vector<int>>& res,vector<int>& temp, int& sum){
        if(sum > target){
            return;
        }

        if(sum == target){
            res.push_back(temp);
            return;
        }

        if(index >= nums.size()){
            if(sum == target){
                res.push_back(temp);
            }
            return;
        }
        //include
        sum += nums[index];
        temp.push_back(nums[index]);
        dfs(index+1, nums, target, res, temp,sum);

        while(index < nums.size()-1 && nums[index] == nums[index+1]){
            index++;
        }
        
        //exclude
        sum -= nums[index];
        temp.pop_back();
        dfs(index+1, nums, target, res, temp, sum);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int sum = 0;
        vector<vector<int>> res;
        vector<int>temp;
        int index=0;
        dfs(index, candidates, target, res, temp, sum);
        return res;
    }
};