class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> st;
        int maxArea = 0;

        for(int i=0;i<heights.size();i++){
            if(st.empty()){
                st.push({heights[i], i});
                continue;
            }

            if(heights[i] >= st.top().first){
                st.push({heights[i], i});
            }
            else{
                int index = -1;

                while(!st.empty() && heights[i] < st.top().first){
                    maxArea = max(maxArea, (i - st.top().second) * st.top().first);
                    index = st.top().second;
                    st.pop();
                }
                st.push({heights[i], index});
            }
        }

        int len = heights.size();

        while(!st.empty()){
            maxArea = max(maxArea, (len - st.top().second) * st.top().first);
            st.pop();
        }

        return maxArea;
    }
};
