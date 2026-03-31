class Solution {
public:
    void solve(vector<int>& nums, int target, vector<vector<int>>& ans, vector<int> temp, int index, int sum){
        if(sum==target){
            ans.push_back(temp);
            return;
        }
        if(index>=nums.size() || sum>target){
            return;
        }

        temp.push_back(nums[index]);
        solve(nums,target,ans,temp,index,sum+nums[index]);
        temp.pop_back();

        //exclude
        solve(nums,target,ans,temp,index+1,sum);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(nums,target,ans,temp,0,0);
        return ans;
    }
};
