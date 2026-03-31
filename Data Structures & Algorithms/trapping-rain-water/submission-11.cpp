class Solution {
public:
    int trap(vector<int>& height) {
        int leftMax=0;
        int rightMax=0;

        int i=0;
        int j=height.size()-1;
        int ans=0;
        while(i<=j){
            if(i>0){leftMax=max(leftMax,height[i-1]);}
            if(j<height.size()-1){rightMax=max(rightMax,height[j+1]);}
            if(height[i]<height[j]){
                if(leftMax-height[i]>0){ans+=leftMax-height[i];}
                i++;
            }
            else{
                if(rightMax-height[j]>0){ans+=rightMax-height[j];}
                j--;
            }
        }
        return ans;
    }
};
