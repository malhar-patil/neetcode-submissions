class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        vector<int> ans;
        
        for(int i=0;i<nums.size();i++){
            int y = target-nums[i];
            if(m.find(y)!=m.end()){
                ans.push_back(m[y]);
                ans.push_back(i);
                return ans;
            }
            else{
                m[nums[i]]=i;
            }
        }
        return ans;
    }
};
