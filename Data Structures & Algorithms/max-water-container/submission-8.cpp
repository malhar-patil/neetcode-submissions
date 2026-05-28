class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxWater = 0;
        int tempWater = 0;

        int l = 0;
        int r = heights.size()-1;

        while(l<r){
            tempWater = min(heights[l], heights[r]) * (r-l);
            maxWater = max(tempWater, maxWater);
            if(heights[l] <= heights[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return maxWater;
    }
};
