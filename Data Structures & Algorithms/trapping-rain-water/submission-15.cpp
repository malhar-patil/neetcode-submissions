class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> prefix(height.size(),0);
        vector<int> suffix(height.size(),0);

        for(int i=1;i<prefix.size();i++){
            prefix[i] = max(height[i-1], prefix[i-1]);
        }

        for(int i=suffix.size()-2;i>=0;i--){
            suffix[i] = max(height[i+1], suffix[i+1]);
        }

        int ans = 0;
        for(int i=0;i<height.size();i++){
            ans+=max(0,min(prefix[i], suffix[i])-height[i]);
        }
        return ans;

        // 0 0 2 2 3 3 3 3 3 3

        // 3 3 3 3 3 3 3 2 1 0
    }
};
