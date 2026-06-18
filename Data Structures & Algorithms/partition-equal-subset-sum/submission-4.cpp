class Solution {
public:
    
    bool dfs(int index, int temp, vector<int>& nums, int total, map<pair<int,int>, bool>& m){
        if(index >= nums.size()){
            if((double)temp == (double)total/2){
                return true;
            }
            return false;
        }

        if(m.find({index, temp})!= m.end()){
            return m[{index, temp}];
        }
        
        m[{index, temp}] = (dfs(index+1, temp + nums[index], nums, total, m) || dfs(index+1, temp, nums, total, m));
        return m[{index, temp}];
    }
    bool canPartition(vector<int>& nums) {
        map<pair<int,int>, bool> m;
        int temp = 0;
        int total = 0;
        for(int i=0;i<nums.size();i++){
            total += nums[i];
        }
        return dfs(0, temp, nums, total, m);
    }
};
