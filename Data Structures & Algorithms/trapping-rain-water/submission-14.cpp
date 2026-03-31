class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>prefix(height.size(),0);
        vector<int>suffix(height.size(),0);

        int maxHeight = 0;
        for(int i=1;i<prefix.size();i++){
            maxHeight = max(maxHeight, height[i-1]);
            prefix[i] = maxHeight;
            
        }
        maxHeight = 0;
        for(int i=suffix.size()-2;i>=0;i--){
            maxHeight = max(maxHeight, height[i+1]);
            suffix[i] = maxHeight;
            
        }

        int trapWater = 0;
        for(int i=0;i<height.size();i++){
            trapWater += max(0, min(suffix[i],prefix[i])-height[i]);
        }
        return trapWater;
    }
};
