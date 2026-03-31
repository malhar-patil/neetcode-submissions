class Solution {
public:
    int trap(vector<int>& height) {
        int maxLeft=height[0];
        int maxRight=height[height.size()-1];
        int i=0;
        int j=height.size();

        int ans=0;

        while(i<j){
            if(maxLeft<maxRight){
                i++;
                int temp = maxLeft - height[i];
                maxLeft=max(maxLeft,height[i]);
                if(temp<0){
                    continue;
                }
                ans+=temp;
            }
            else{
                j--;
                int temp = maxRight - height[j];
                maxRight= max(maxRight,height[j]);
                if(temp<0){
                    continue;
                }
                ans+=temp;
            }
        }
        return ans;
    }
};
