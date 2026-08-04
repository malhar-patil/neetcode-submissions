class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for(int i=0;i<nums.size();i++){
            res = res ^ nums[i];
        }

        int res2 = 0;
        for(int i=0;i<=nums.size();i++){
            res2 = res2 ^ i;
        }

        return res^res2;
    }
};
