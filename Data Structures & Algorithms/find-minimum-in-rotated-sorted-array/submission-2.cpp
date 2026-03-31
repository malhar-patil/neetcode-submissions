class Solution {
public:
    int getPivot(vector<int>& arr){
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
    int findMin(vector<int> &nums) {
        if(nums[0]<nums[nums.size()-1]){
            return nums[0];
        }
        int pivot = getPivot(nums);
        return nums[pivot];
    }
};
