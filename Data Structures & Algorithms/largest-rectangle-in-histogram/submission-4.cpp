class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> arr;

        for(int i=0;i<heights.size();i++){
            int s=i;
            int e=i;

            while(s>=1 && heights[s-1]>=heights[i]){
                s--;
            }
            while(e<heights.size()-1 && heights[e+1]>=heights[i]){
                e++;
            }

            arr.push_back((e-s+1) * heights[i]);
        }

        int ans = INT_MIN;
        for(int i=0;i<arr.size();i++){
            ans = max(ans,arr[i]);
        }
        return ans;
    }
};
