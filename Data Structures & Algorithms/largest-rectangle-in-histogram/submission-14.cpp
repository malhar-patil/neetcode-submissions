class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //height, index
        stack<pair<int, int>> st;
        int maxArea;

        for(int i=0;i<heights.size();i++){
            if(st.empty()){
                st.push({heights[i], i});
                continue;
            }

            if(heights[i] >= st.top().first){
                st.push({heights[i], i});
            }
            else{
                int index = i;
                while(!st.empty() && st.top().first > heights[i]){
                    maxArea = max(maxArea, (i-st.top().second)*st.top().first);
                    index = st.top().second;
                    st.pop();
                }
                st.push({heights[i], index});
            }
        }
        int temp = heights.size();
        while(!st.empty()){
            maxArea = max(maxArea, (temp-st.top().second)*st.top().first);
            st.pop();
        }
        return maxArea;
    }
};
