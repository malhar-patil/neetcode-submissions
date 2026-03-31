class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> m;
        int res = 0;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]=true;
        }
        
        for(int i=0;i<nums.size();i++){
            int temp = 0;
            int num = nums[i];
            while(m[num]){
                temp++;
                num++;
            }
            res = max(temp,res);
        }
        return res;
    }
};
