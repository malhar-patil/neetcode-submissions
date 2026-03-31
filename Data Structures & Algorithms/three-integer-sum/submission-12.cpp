class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int>temp;
        for(int i=0;i<nums.size()-2;i++){
            if(i>0 && nums[i]==nums[i-1]){continue;}
            int s=i+1;
            int e=nums.size()-1;
            int target = -nums[i];

            while(s<e){
                while(s>i+1 && nums[s]==nums[s-1] && s<e){s++;}
                while(e<nums.size()-2 && nums[e]==nums[e+1] && s<e){e--;}
                if(s==e){break;}
                if(nums[s]+nums[e]==target){
                    temp.clear();
                    temp.push_back(nums[i]);
                    temp.push_back(nums[s]);
                    temp.push_back(nums[e]);
                    ans.push_back(temp);
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
        return ans;
    }
};
