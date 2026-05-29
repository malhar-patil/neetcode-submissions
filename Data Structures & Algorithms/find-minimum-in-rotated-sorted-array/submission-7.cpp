class Solution {
public:
    int getPivot(vector<int>& nums){
        int s = 0;
        int e = nums.size()-1;

        while(s < e){
            int mid = s+(e-s)/2;

            if(nums[mid] >= nums[0]){
                s=mid+1;
            }
            else{
                e = mid;
            }
        }
        return s;
    }
    int findMin(vector<int> &nums) {
        if(nums[0] <= nums[nums.size()-1]){
            return nums[0];
        }
        int pivot = getPivot(nums);
        return nums[pivot];
    }
};
