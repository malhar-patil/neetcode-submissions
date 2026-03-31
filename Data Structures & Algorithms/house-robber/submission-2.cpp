class Solution {
public:
    int solve(int index, vector<int>& nums, unordered_map<int,int>& m){
        if(index>=nums.size()){
            return 0;
        }
        if(m.find(index) != m.end()){
            return m[index];
        }
        int x = solve(index+2, nums, m);
        int y = solve(index+3, nums, m);
        m[index] = max(x,y) + nums[index];
        return m[index];
    }
    int rob(vector<int>& nums) {
        unordered_map<int,int>m;
        return max(solve(0,nums,m), solve(1,nums,m));
    }
};