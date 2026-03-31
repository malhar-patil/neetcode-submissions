class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,bool> m;
        for(int i=0;i<nums.size();i++){
            if(m[nums[i]]==true){
                return true;
            }
            else{
                m[nums[i]]=true;
            }
        }
        return false;
    }
};