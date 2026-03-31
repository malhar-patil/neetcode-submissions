class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size()-2;i++){
            if(i!=0 && nums[i]==nums[i-1]){
                continue;
            }
            int s=i+1;
            int e=nums.size()-1;
            int target = nums[i]*-1;
            while(s<e){
                if(nums[s]+nums[e]==target){
                    vector<int>temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[s]);
                    temp.push_back(nums[e]);
                    s++;
                    while(nums[s]==nums[s-1] && s<e){
                        s++;
                    }
                    ans.push_back(temp);
                }
                else if(nums[s]+nums[e]<target){
                    s++;
                }
                else{
                    e--;
                }
            }
        }
        return ans;
    }
};
