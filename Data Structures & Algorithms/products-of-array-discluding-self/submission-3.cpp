class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int temp = nums[0];

        vector<int> prefix(nums.size(),1);
        vector<int> suffix(nums.size(),1);

        for(int i=1;i<nums.size();i++){
            prefix[i] = prefix[i-1]*temp;
            temp=nums[i];
        }

        temp = nums[nums.size()-1];

        for(int i=nums.size()-2;i>=0;i--){
            suffix[i] = suffix[i+1]* temp;
            temp=nums[i];
        }

        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            ans.push_back(prefix[i]*suffix[i]);
        }
        return ans;

    }
};

// 1 1 2 8
// 1 6 24 48


