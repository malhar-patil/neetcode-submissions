class Solution {
public:
    int solve(int index, int limit, vector<int>& nums, unordered_map<int,int>& m){
        if(index<limit){
            return 0;
        }
        if(m.find(index) != m.end()){
            return m[index];
        }
        
        m[index] = max(solve(index-1, limit, nums, m), solve(index-2, limit, nums, m) + nums[index]);
        return m[index];
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        unordered_map<int,int>m;
        int x = solve(nums.size()-1, 1, nums, m);
        m.clear();
        int y = solve(nums.size()-2, 0, nums, m);
        return max(x,y);
    }
};
