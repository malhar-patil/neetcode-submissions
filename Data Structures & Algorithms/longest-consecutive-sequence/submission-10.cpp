class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans=0;
        int temp=1;

        unordered_map<int,bool> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]=true;
        }

        for(int i=0;i<nums.size();i++){
            temp=1;
            int num=nums[i];
            while(m.find(num+1)!=m.end()){
                num++;
                temp++;
            }
            ans=max(ans,temp);
        }
        return ans;
    }
};
