class Solution {
public:
    int trap(vector<int>& height) {
        int i=0;
        int j=height.size()-1;

        vector<int>prefix(height.size(),0);
        vector<int>suffix(height.size(),0);
        int tempMax=0;
        for(int i=1;i<prefix.size();i++){
            tempMax=max(tempMax,height[i-1]);
            prefix[i]=tempMax;
        }
        tempMax=0;
        for(int i=height.size()-2;i>=0;i--){
            tempMax=max(tempMax,height[i+1]);
            suffix[i]=tempMax;
        }
        int ans=0;
        for(int i=0;i<height.size();i++){
            int res = min(prefix[i],suffix[i])-height[i];
            if(res>=0){
                ans+=res;
            }
        }
        return ans;
    }
};
