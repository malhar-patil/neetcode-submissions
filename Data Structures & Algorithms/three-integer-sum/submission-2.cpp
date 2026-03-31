class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        // -4 -1 -1 0 1 2
        set<vector<int>> ans;
        vector<int> temp;
        for(int i=0;i<nums.size()-2;i++){
            int target = nums[i] * -1;
            int j=i+1;
            int k=nums.size()-1;

            while(j<k){
                if(nums[j]+nums[k] == target){
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    sort(temp.begin(),temp.end());
                    ans.insert(temp);
                    temp.clear();
                    j++;
                    k--;
                }
                else if(nums[j]+nums[k] >= target){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        vector<vector<int>> final (ans.begin(),ans.end());
        return final;
    }
};
