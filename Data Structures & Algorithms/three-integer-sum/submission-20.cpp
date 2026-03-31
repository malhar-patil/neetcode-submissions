class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int target = -nums[i];
            int s=i+1;
            int e=nums.size()-1;
            while(s<e){
                while(s>i+1 && s<e && nums[s]==nums[s-1]){
                    s++;
                }
                while(e<nums.size()-1 && s<e && nums[e]==nums[e+1]){
                    e--;
                }
                if(s>=e){break;}
                if(nums[s]+nums[e]==target){
                    res.push_back({nums[i],nums[s],nums[e]});
                    s++;
                    e--;
                }
                else if(nums[s]+nums[e]<target){
                    s++;
                }
                else{
                    e--;
                }
            }
        }
        return res;
    }
};
