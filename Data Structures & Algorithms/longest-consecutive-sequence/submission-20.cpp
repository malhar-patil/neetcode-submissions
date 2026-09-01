class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> m;
        unordered_set<int> visited;

        for(int i=0;i<nums.size();i++){
            m.insert(nums[i]);
        }

        int ans = 0;
        for(int i=0;i<nums.size();i++){
            int num = nums[i];
            int temp = 1;
            if(!m.contains(num-1) && !visited.contains(num)){
                while(m.contains(num+1)){
                    temp++;
                    num++;
                }
            }
            visited.insert(nums[i]);
            ans = max(temp, ans);
        }
        return ans;
    }
};
