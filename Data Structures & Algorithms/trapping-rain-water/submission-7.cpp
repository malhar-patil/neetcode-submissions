class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>prefix(height.size(),0);
        vector<int>suffix(height.size(),0);
        int maxHeight=0;
        for(int i=1;i<height.size();i++){
            maxHeight=max(maxHeight,height[i-1]);
            prefix[i]=maxHeight;
        }

        maxHeight=0;
        for(int i=height.size()-2;i>=0;i--){
            maxHeight=max(maxHeight,height[i+1]);
            suffix[i]=maxHeight;
        }

        int ans=0;
        for(int i=0;i<height.size();i++){
            int temp=min(prefix[i],suffix[i])-height[i];
            if(temp<0){continue;}
            ans+=temp;
        }
        return ans;
    }
};
// left min 0 0 2 2 3 3 3 3 3 3
//right min 3 3 3 3 3 3 3 2 1 0
             