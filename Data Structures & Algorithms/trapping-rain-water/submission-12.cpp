class Solution {
public:
    int trap(vector<int>& height) {
        int leftMax=height[0];
        int rightMax=height[height.size()-1];

        int i=0;
        int j=height.size()-1;
        int ans=0;
        while(i<=j){
            if(i>0){leftMax=max(leftMax,height[i-1]);}
            if(j<height.size()-1){rightMax=max(rightMax,height[j+1]);}
            if(leftMax<=rightMax){
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
