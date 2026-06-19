class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = INT_MAX;
        int sum = 0;
        int l=0;

        for(int r=0;r<nums.size();r++){
            if(sum < target){
                sum +=nums[r];
                
            }
            while(sum >= target && l<=r){
                minLen = min(minLen, r-l+1);
                sum -= nums[l];
                l++;
            }       
        }
        if(minLen == INT_MAX){
            return 0;
        }
        return minLen;
    }
};