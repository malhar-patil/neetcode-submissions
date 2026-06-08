class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() <= 1){
            return true;
        }

        int goal = nums.size()-1;
        int curr = nums.size()-2;

        while(curr >= 0){
            if(nums[curr] >= goal-curr){
                goal = curr;
            }
            curr--;
        }

        
        if(goal == 0){
            return true;
        }
        return false;
    }
};
