class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans = INT_MIN;

        int s=0;
        int e=heights.size()-1;

        while(s<e){
            ans = max(ans, (min(heights[s],heights[e]) * (e-s)));
            if(heights[s]<heights[e]){
                s++;
            }
            else{
                e--;
            }
        }
        return ans;
    }
};
