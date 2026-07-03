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
        dfs(index, nums, target, res, temp,sum);


        //exclude
        sum -= nums[index];
        temp.pop_back();
        dfs(index+1, nums, target, res, temp, sum);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        vector<vector<int>> res;
        vector<int>temp;
        int index=0;
        dfs(index, nums, target, res, temp, sum);
        return res;
    }
};
