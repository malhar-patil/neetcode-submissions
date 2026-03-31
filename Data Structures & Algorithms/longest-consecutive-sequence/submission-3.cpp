class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<=1){
            return nums.size();
        }
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i])==m.end()){
                m[nums[i]] = 1;
            }
        }

        int ans = INT_MIN;
        for(int i=0;i<nums.size();i++){
            int num = nums[i];
            int temp = 0;
            while(m.find(num)!=m.end()){
                temp++;
                num++;
            }
            ans=max(temp,ans);
        }
        return ans;
    }
};
