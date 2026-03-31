class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>  res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int target = -1*nums[i];
            int s=i+1;
            int e=nums.size()-1;

            while(s<e){
                if(s>i+1 && nums[s]==nums[s-1]){
                    s++;
                    continue;
                }
                if(e<nums.size()-1 && nums[e]==nums[e+1]){
                    e--;
                    continue;
                }      
                          
                if(nums[s]+nums[e]==target){
                    res.push_back({nums[i],nums[s],nums[e]});
                    s++;
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
