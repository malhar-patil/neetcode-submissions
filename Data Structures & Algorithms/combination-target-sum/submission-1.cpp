class Solution {
public:
    void solve(vector<int>& nums, int target,vector<vector<int>>& ans,vector<int> temp, int sum, int index){
        if(index>=nums.size()){
            return;
        }
        solve(nums,target,ans,temp,sum,index+1);
        if(sum+nums[index]<=target){
            sum+=nums[index];
            temp.push_back(nums[index]);
            if(sum==target){
                ans.push_back(temp);
            }
            solve(nums,target,ans,temp,sum,index);
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(nums,target,ans,temp,0,0);
        return ans;
    }
};
