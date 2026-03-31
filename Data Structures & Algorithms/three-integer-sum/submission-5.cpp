class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> tempSet;
        vector<int> temp;
        for(int i=0;i<nums.size();i++){
            int s=i+1;
            int e=nums.size()-1;
            while(s<e){
                if(nums[i] + nums[s] + nums[e] == 0){
                    temp.push_back(nums[i]);
                    temp.push_back(nums[s]);
                    temp.push_back(nums[e]);
                    sort(temp.begin(),temp.end());
                    tempSet.insert(temp);
                    temp.clear();
                    s++;e--;
                }
                else if(nums[i] + nums[s] +nums[e] < 0){
                    s++;
                }
                else{
                    e--;
                }
            }
        }
        vector<vector<int>> ans(tempSet.begin(),tempSet.end());
        return ans;        
    }
};
