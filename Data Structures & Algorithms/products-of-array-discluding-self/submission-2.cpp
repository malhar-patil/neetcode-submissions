class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //1 1 2 8
        //48 24 6 1 
        vector<int> p(nums.size(),1);
        vector<int> s(nums.size(),1);

        for(int i=1;i<nums.size();i++){
            p[i] = p[i-1]*nums[i-1];
        }

        for(int i=nums.size()-2;i>=0;i--){
            s[i] = s[i+1]*nums[i+1];
        }

        vector<int> ans;
        for(int i=0;i<p.size();i++){
            ans.push_back(p[i]*s[i]);
        }
        return ans;
    }
};
