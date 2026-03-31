class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxEnding = nums[0];
        int minEnding = nums[0];
        int res = nums[0];
        for(int i=1;i<nums.size();i++){
            int temp =maxEnding;
            maxEnding = max(nums[i], max(nums[i] * maxEnding, nums[i]*minEnding));
            minEnding = min(nums[i], min(nums[i] * minEnding, nums[i]*temp));
            res = max(max(maxEnding, minEnding), res);
            cout<<maxEnding<<" "<<minEnding<<" "<<res<<endl;
        }
        return res;
    }
};
