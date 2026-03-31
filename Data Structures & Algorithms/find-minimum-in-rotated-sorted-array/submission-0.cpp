class Solution {
public:
    int getPivot(vector<int> &nums){
        int s=0;
        int e=nums.size()-1;
        int mid=s+(e-s)/2;

        while(s<e){
            if(nums[0]<=nums[mid]){
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
        int pivot=-1;
        if(nums[0]<=nums[nums.size()-1]){
            pivot = -1;
        }
        else{
            pivot = getPivot(nums);
        }

        if(pivot == -1){
            return nums[0];
        }
        return nums[pivot];
    }
};
