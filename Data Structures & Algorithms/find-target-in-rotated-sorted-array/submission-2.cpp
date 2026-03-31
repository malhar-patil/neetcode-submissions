class Solution {
public:
    int getPivot(vector<int>arr){
        int s=0;
        int e=arr.size()-1;
        int mid=s+(e-s)/2;

        while(s<e){
            if(arr[mid]>=arr[0]){
                s=mid+1;
            }
            else{
                e=mid;
            }
            mid=s+(e-s)/2;
        }
        return s;
    }
    int binarySearch(vector<int>& nums, int target,int s,int e){
        int mid=s+(e-s)/2;
        while(s<=e){
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int pivot = -1;
        if(nums[0]>nums[nums.size()-1]){
            pivot = getPivot(nums);
        }

        if(pivot == -1){
            return binarySearch(nums,target,0,nums.size()-1);
        }
        if(target>=nums[0]&&target<=nums[pivot-1]){
            return binarySearch(nums,target,0,pivot-1);
        }
        return binarySearch(nums,target,pivot,nums.size()-1);

    }
};
