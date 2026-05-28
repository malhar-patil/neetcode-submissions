class Solution {
public:
    int trap(vector<int>& height) {
        int maxL = height[0];
        int maxR = height[height.size()-1];
        int ans = 0;

        int l = 0;
        int r = height.size()-1;

        while(l<r){
            if(maxL <= maxR){
                l++;
                ans += max(0, maxL - height[l]);
                maxL = max(maxL, height[l]);
            }
            else{
                r--;
                ans += max(0, maxR - height[r]);
                maxR = max(maxR, height[r]);  
            }
        }
        return ans;
    }
};
