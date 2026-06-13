class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1){return nums[0];}
        if(nums.size()==2){return max(nums[0], nums[1]);}
        
        int a, b = 0;
        vector<int> arr(nums.size()+1, 0);

        for(int i=0;i<nums.size()-1;i++){
            arr[i+2] = max(arr[(i+2)-1], nums[i] + arr[(i+2)-2]);
        }

        a = arr[arr.size()-1]; arr.assign(nums.size()+1, 0);

        for(int i=1;i<nums.size();i++){
            arr[i+1] = max(arr[(i+1)-1], nums[i] + arr[(i+1)-2]);
        }
        b = arr[arr.size()-1];

        return max(a,b);
    }
};
