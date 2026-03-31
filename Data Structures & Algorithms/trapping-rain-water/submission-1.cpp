class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> prefix(height.size(),0);
        vector<int> suffix(height.size(),0);

        int maxCap = 0;
        for(int i=0;i<height.size();i++){
            prefix[i] = maxCap;
            maxCap = max(maxCap, height[i]);
        }
        maxCap=0;
        for(int i=height.size()-1;i>=0;i--){
            suffix[i] = maxCap;
            maxCap = max(maxCap,height[i]);
        }

        int ans=0;
        for(int i=0;i<height.size();i++){
            int temp = min(suffix[i],prefix[i]) - height[i];
            if(temp<0){
                continue;
            }
            ans+=temp;
        }
        return ans;
    }
};
