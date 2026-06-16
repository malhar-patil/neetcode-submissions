class Solution {
public:
    void dfs(int index, vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp){
        if(index >= nums.size()){
            ans.push_back(temp);
            return;
        }

        //include
        temp.push_back(nums[index]);
        dfs(index+1, nums, ans, temp);

        //exclude
        temp.pop_back();
        dfs(index+1, nums, ans, temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(0, nums, ans, temp);
        return ans;
    }
};
