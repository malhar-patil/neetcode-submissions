class Solution {
public:
    int dfs(vector<int>& nums, unordered_map<int,int>& m, int index){
        if(index >= nums.size()){
            return 0;
        }

        if(m.find(index) != m.end()){
            return m[index];
        }

        m[index] = nums[index] + max(dfs(nums, m, index+2), dfs(nums, m, index+3));
        return m[index];
    }
    int rob(vector<int>& nums) {

        if(nums.size() == 2){
            return max(nums[0], nums[1]);
        }

        unordered_map<int,int> m;
        return max(dfs(nums, m , 0), dfs(nums, m, 1));
    }
};
