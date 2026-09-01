class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0;
        int j=numbers.size()-1;

        while(i<j){
            int val = numbers[i] + numbers[j];
            if(val == target){
                return {i+1, j+1};
            }
            else if(val < target){
                i++;
            }
            else{
                j--;
            }
        }

        return {-1,-1};
    }
};
