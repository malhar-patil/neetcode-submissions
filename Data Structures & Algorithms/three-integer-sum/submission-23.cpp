class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<(int)nums.size()-2;i++){
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            int j = i+1;
            int k = nums.size() - 1;
            int target = -nums[i];

            while(j<k){
                while(j>i+1 && nums[j] == nums[j-1]){
                    j++;
                }
                while(k<nums.size()-1 && nums[k] == nums[k+1]){
                    k--;
                } 

                if(j>=k){break;}

                int val = nums[j] + nums[k];

                if(val == target){
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if(val < target){
                    j++;
                }
                else{
                    k--;
                }
            }
        }

        return ans;
    }
};
