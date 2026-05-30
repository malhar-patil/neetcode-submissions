class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() <= 1){
            return true;
        }
        int goal = nums.size()-1;
        int curr = nums.size()-2;

        while(curr >= 0){
            int jumpsRequired = goal - curr;
            //cout<<"->"<<jumpsRequired<<endl;
            if(nums[curr] >= jumpsRequired){
                goal = curr;
                curr--;
            }
            else{
                curr--;
            }
            //cout<<curr<<" "<<goal<<endl;
        }
        if(goal == 0){
            return true;
        }
        return false;
    }
};
