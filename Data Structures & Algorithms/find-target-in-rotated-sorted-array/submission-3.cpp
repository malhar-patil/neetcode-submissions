class Solution {
public:
    int getPivot(vector<int>&nums){
        if(nums[0]<=nums[nums.size()-1]){
            return 0;
        }

        int s=0;
        int e=nums.size()-1;
        while(s<e){
            int mid=s+(e-s)/2;
            if(nums[0]<=nums[mid]){
                s=mid+1;
            }
            else{
                e=mid;
            }
        }
        return e;
    }
    int binarySearch(vector<int>&nums,int target,int s, int e){
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int pivot = getPivot(nums);
        if(pivot == 0){
            return binarySearch(nums,target, 0, nums.size()-1);
        }
        if(target>=nums[0] && target<=nums[pivot-1]){
            return binarySearch(nums,target, 0, pivot-1);
        }
        else{
            return binarySearch(nums,target, pivot, nums.size()-1);
        }
        
    }
};
