class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> prefix(height.size(),0);
        vector<int> suffix(height.size(),0);

        int maxHeight = 0;
        for(int i=0;i<height.size();i++){
            prefix[i] = maxHeight;
            maxHeight = max(maxHeight, height[i]);
        }

        maxHeight = 0;
        for(int i=height.size()-1;i>=0;i--){
            suffix[i] = maxHeight;
            maxHeight = max(maxHeight,height[i]);
        }

        int ans=0;
        for(int i=0;i<height.size();i++){
            int temp = min(prefix[i],suffix[i]) - height[i];
            if(temp>0){
                ans+=temp;
            }
        }
        return ans;
    }
};
