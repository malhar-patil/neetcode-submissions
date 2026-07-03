class Solution {
public:
    void dfs(int index, vector<int> nums, vector<vector<int>>& res){
        if(index >= nums.size()){
            res.push_back(nums);
            return;
        }

        for(int i=index;i<nums.size();i++){
            swap(nums[index], nums[i]);
            dfs(index+1, nums, res);
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int index = 0;
        dfs(index, nums, res);
        return res;
    }
};
