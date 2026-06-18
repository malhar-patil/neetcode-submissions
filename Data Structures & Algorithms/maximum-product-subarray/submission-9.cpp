class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        int currMax = nums[0];
        int currMin = nums[0];
        int prod = INT_MIN;

        for(int i=1;i<nums.size();i++){
            int temp = currMax;
            currMax = max(max(nums[i] * currMax, nums[i] * currMin), nums[i]);
            currMin = min(min(nums[i] * temp, nums[i] * currMin), nums[i]);

            prod = max(prod, currMax);
        }

        return prod;
    }
};
