class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1){return nums[0];}
        if(nums.size()==2){return max(nums[0], nums[1]);}
        int a = 0;
        int b = 0;

        for(int i=0;i<nums.size()-1;i++){
            int temp = nums[i] + a;
            a = b;
            b = max(b, temp);
        }
         int ans1 = b;
         a=0;b=0;

        for(int i=1;i<nums.size();i++){
            int temp = nums[i] + a;
            a = b;
            b = max(b, temp);
        }

        return max(ans1, b);
    }
};
