class Solution {
public:
    
    bool dfs(int index, int temp, vector<int>& nums, int total, vector<vector<int>>& m){
        if(index >= nums.size()){
            if(temp == total/2 && total%2 == 0){
                return true;
            }
            return false;
        }

        if(m[index][temp]!=-1){
            return m[index][temp];
        }
        
        m[index][temp] = (dfs(index+1, temp + nums[index], nums, total, m) || dfs(index+1, temp, nums, total, m));
        return m[index][temp];
    }
    bool canPartition(vector<int>& nums) {
        
        int temp = 0;
        int total = 0;
        for(int i=0;i<nums.size();i++){
            total += nums[i];
        }
        vector<vector<int>> m(nums.size()+1, vector<int>(total + 1, -1));
        return dfs(0, temp, nums, total, m);
    }
};
