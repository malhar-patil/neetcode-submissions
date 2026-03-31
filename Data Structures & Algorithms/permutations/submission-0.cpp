class Solution {
public:
    void solve(vector<int>nums,vector<vector<int>>&ans,vector<int>temp,int index){
        if(index>=nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i=index;i<nums.size();i++){
            swap(nums[i],nums[index]);
            solve(nums,ans,temp,index+1);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>temp;
        solve(nums,ans,temp,0);
        return ans;
    }
};
