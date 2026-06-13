class Solution {
public:
    int dfs(int index, int end, vector<int>& nums, unordered_map<int,int>& m){
        if(index > end){
            return 0;
        }

        if(m.find(index) != m.end()){
            return m[index];
        }

        m[index] = max(dfs(index+1, end, nums, m), nums[index] + dfs(index+2, end, nums, m));
        return m[index];
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1){return nums[0];}
        if(nums.size() == 2){return max(nums[0], nums[1]);}
        unordered_map<int,int> m;
        int a = dfs(0, nums.size()-2, nums, m);
        m.clear();
        int b = dfs(1, nums.size()-1, nums, m);
        return max(a, b);
    }
};
