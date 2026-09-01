class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> prefix(height.size(), 0);
        vector<int> suffix(height.size(), 0);

        for(int i=1;i<height.size();i++){
            prefix[i] = max(prefix[i-1], height[i-1]);
        }

        for(int i=height.size()-2;i>=0;i--){
            suffix[i] = max(suffix[i+1], height[i+1]);
        }

        int water = 0;

        for(int i=0;i<height.size();i++){
            water += max(min(prefix[i],suffix[i])-height[i], 0);
        }
        return water;
    }
};
