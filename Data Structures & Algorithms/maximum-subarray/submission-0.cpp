class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int temp = 0;
        int ans = INT_MIN;
        for(int i=0;i<nums.size();i++){
            temp = max(nums[i], temp+nums[i]);
            ans = max(temp,ans);
        }
        return ans;
    }
};
