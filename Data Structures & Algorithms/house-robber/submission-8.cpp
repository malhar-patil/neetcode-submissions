class Solution {
public:
    int rob(vector<int>& nums) {
        //bottom-up
        vector<int> arr(nums.size()+2, 0);

        for(int i=2;i<arr.size();i++){
            arr[i] = max(arr[i-1], nums[i-2] + arr[i-2]);
        }

        return arr[arr.size()-1];
    }
};
