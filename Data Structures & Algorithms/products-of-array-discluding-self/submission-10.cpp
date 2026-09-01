class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);

        for(int i=1;i<nums.size();i++){
            res[i] = nums[i-1] * res[i-1];
        }

        int prev = nums[nums.size()-1];
        nums[nums.size()-1] = 1;
        for(int i=nums.size()-2;i>=0;i--){
            int prod = prev * nums[i+1];
            prev = nums[i];
            nums[i] = prod;
        }

        for(int i=0;i<nums.size();i++){
            res[i] *= nums[i];
        }
        return res;
    }
};
