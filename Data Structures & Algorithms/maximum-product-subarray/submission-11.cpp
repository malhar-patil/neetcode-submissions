class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN;
        int mx = nums[0];
        int mn = nums[0];

        for(int i=1;i<nums.size();i++){
            int num1 = mn * nums[i];
            int num2 = mx * nums[i];

            mx = max(max(num1, num2), nums[i]);
            mn = min(min(num1, num2), nums[i]);

            res = max(res, mx);
            
        }
        res = max(res, mx);
        return res;

    }
};
