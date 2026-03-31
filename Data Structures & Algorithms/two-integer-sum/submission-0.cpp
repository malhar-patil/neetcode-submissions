class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> freq;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            int y=target-nums[i];
            if(freq.find(y)!=freq.end()){
                ans.push_back(freq[y]);
                ans.push_back(i);
                return ans;
                
            }
            else{
                freq[nums[i]]=i;
            }
        }
        return ans;

    }
};
