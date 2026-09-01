class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> m;

        for(int i=0;i<nums.size();i++){
            m.insert(nums[i]);
        }

        int ans = 0;
        for(int i=0;i<nums.size();i++){
            int num = nums[i];
            int temp = 1;
            if(m.contains(num+1)){cout<<num<<endl;}
            if(!m.contains(num-1) && m.contains(num+1)){
                while(m.contains(num+1)){
                    temp++;
                    num++;
                }
            }
            ans = max(temp, ans);
        }
        return ans;
    }
};
