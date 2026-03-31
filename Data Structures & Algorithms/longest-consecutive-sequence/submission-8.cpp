class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<=1){
            return nums.size();
        }
        unordered_map<int,bool> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]=true;
        }

        int temp=1;
        int ans=1;
        int num=nums[0];
        for(int i=0;i<nums.size();i++){
            int num = nums[i];
            while(m.find(num+1)!=m.end()){
                temp++;
                num++;
            }
            ans=max(ans,temp);
            temp=1;
        }
        // while(m.find(num+1)!=m.end()){
        //     temp++;
        //     num++;
        // }
        // ans=max(ans,temp);
        return ans;

    }
};
