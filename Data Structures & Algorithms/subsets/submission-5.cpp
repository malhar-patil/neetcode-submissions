class Solution {
public:
    void dfs(int index, vector<int>& nums, vector<int> temp, vector<vector<int>>& res){
        if(index >= nums.size()){
            res.push_back(temp);
            return;
        }

        //include
        temp.push_back(nums[index]);
        dfs(index+1, nums, temp, res);
        //exclude

        temp.pop_back();
        dfs(index+1, nums, temp, res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        dfs(0, nums, temp, res);
        return res;
    }
};
