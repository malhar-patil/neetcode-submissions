class Solution {
public:
    int solve(int index, vector<int>& nums, unordered_map<int,int>& m){
        if(index<0){
            return 0;
        }
        if(m.find(index) != m.end()){
            return m[index] + nums[index];
        }
        int x = solve(index-2, nums, m);
        int y = solve(index-3, nums, m);
        m[index] = max(x,y);
        if(x>y){
            return x + nums[index];
        }
        return y + nums[index];
    }
    int rob(vector<int>& nums) {
        unordered_map<int,int>m;
        return max(solve(nums.size()-1,nums,m), solve(nums.size()-2,nums,m));
    }
};