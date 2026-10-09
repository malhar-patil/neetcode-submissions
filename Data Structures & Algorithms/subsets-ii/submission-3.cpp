class Solution {
public:
    void dfs(int index, vector<int>& nums, vector<int>& temp, vector<vector<int>>& res){
        if(index >= nums.size()){
            res.push_back(temp);
            return;
        }

        //include
        temp.push_back(nums[index]);
        dfs(index+1, nums, temp, res);
        temp.pop_back();

        //exclude;
        int next = index + 1;
        while(next < nums.size() && nums[index] == nums[next]){
            next++;
        }
        dfs(next, nums, temp, res);

        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int index = 0;
        vector<int> temp;
        vector<vector<int>>res;
        dfs(index, nums, temp, res);
        return res;
    }
};
