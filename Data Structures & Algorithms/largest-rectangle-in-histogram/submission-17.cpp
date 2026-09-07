class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> st;
        int maxArea = 0;

        for(int i=0;i<heights.size();i++){
            if(st.empty()){
                st.push({i, heights[i]});
                continue;
            }

            if(heights[i] >= st.top().second){
                st.push({i, heights[i]});
                continue;
            }

            int index = -1;
            while(!st.empty() && heights[i] < st.top().second){
                int temp = (i-st.top().first) * st.top().second;
                index = st.top().first;
                maxArea = max(maxArea, temp);
                st.pop();
            }
            st.push({index, heights[i]});
        }
        int j = heights.size();
        while(!st.empty()){
            maxArea = max(maxArea, ((j-st.top().first) * st.top().second));
            st.pop();
        }
        return maxArea;
    }
};
