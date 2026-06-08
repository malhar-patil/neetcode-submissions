class Solution {
public:
    int jump(vector<int>& nums) {
        int minJumps = 0;
        int index = 0;

        while(index < nums.size()-1){
            int i = index+1;
            int maxDistance = 0;
            int maxIndex = 0;

            while(i < nums.size() && i <= (index + nums[index])){

                if(i == nums.size()-1){
                    return minJumps+1;
                }

                if(i + nums[i] >= maxDistance){
                    maxDistance = nums[i] + i;
                    maxIndex = i;
                }
                i++;                
            }
            minJumps++;
            index = maxIndex;
        }
        return minJumps;
    }
};
