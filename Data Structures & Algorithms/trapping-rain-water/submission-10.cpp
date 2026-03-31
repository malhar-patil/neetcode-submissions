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
            int res=0;
            if(height[i]<height[j]){
                res=leftMax-height[i];
                i++;
            }
            else{
                res=rightMax-height[j];
                j--;
            }
            if(res>0){
                ans+=res;
            }
        }
        return ans;
    }
};
