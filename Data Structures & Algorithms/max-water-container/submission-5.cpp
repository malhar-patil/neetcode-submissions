class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxWater=0;

        int i=0;
        int j=heights.size()-1;

        while(i<j){
            int temp = (j-i)*min(heights[i],heights[j]);
            maxWater=max(maxWater,temp);

            if(heights[i]<=heights[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return maxWater;
    }
};
