class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int i=0;i<nums.size()-2;i++){
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }

            int target = -nums[i];
            int s=i+1;
            int e=nums.size()-1;

            while(s<e){
                if(s>i+1 && nums[s] == nums[s-1]){
                    s++;
                    continue;
                }
                if(e<nums.size()-1 && nums[e+1] == nums[e]){
                    e--;
                    continue;
                }

                if(nums[s]+nums[e] == target){
                    ans.push_back({nums[i], nums[s], nums[e]});
                    s++;
                    e--;
                }
                else if(nums[s]+nums[e] < target){
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
