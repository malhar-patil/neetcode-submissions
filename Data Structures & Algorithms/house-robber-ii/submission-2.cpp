class Solution {
public:
    int solve(int index, int limit, vector<int>& nums, unordered_map<int,int>& m){
        if(index<limit){
            return 0;
        }
        if(m.find(index) != m.end()){
            return m[index];
        }
        
        int x = solve(index-2, limit, nums,m);
        int y = solve(index-3, limit, nums,m);
        //return nums[index]+max(x,y);
        m[index] = max(x,y) + nums[index];

        return m[index];
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        unordered_map<int,int>m;
        int res = 0;
        for(int i=nums.size()-1;i>=0;i--){
            if(i == nums.size()-1){
                res = max(res, solve(i, 1, nums, m));
                m.clear();
            }
            else{

                res = max(res, solve(i, 0, nums, m));
            }
        }
        return res;
    }
};
