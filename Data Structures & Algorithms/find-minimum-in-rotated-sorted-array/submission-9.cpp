class Solution {
public:
    int getPivot(vector<int>&nums){
        int s = 0;
        int e = nums.size()-1;

        while(s<e){
            int mid = s+(e-s)/2;

            if(nums[0] <= nums[mid]){
                s=mid+1;
            }
            else{
                e=mid;
            }
        }
        return e;
    }
    int findMin(vector<int> &nums) {
        if(nums[0] <= nums[nums.size()-1]){
            return nums[0];
        }
        return nums[getPivot(nums)];
    }
};
