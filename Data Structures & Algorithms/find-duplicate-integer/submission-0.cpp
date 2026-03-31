class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=0;
        int fast=0;

        while(true){
            slow = nums[nums[slow]];
            fast = nums[nums[nums[fast]]];

            if(nums[slow]==nums[fast]){
                break;
            }
        }

        int slow2=0;
        while(true){
            if(nums[slow]==nums[slow2]){
                return nums[slow];
            }
            slow = nums[slow];
            slow2 = nums[slow2];
        }
        return -1;
    }
};
