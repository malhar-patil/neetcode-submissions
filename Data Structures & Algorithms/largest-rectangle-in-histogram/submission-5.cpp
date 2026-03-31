class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> st;
        int maxArea=0;
        int index=0;
        int i=0;
        for(i=0;i<heights.size();i++){
            if(st.empty()){
                pair<int,int> p{index,heights[i]};
                st.push(p);
                continue;
            }

            if(!st.empty() && heights[i]>=st.top().second){
                st.push({i,heights[i]});
            }
            else{
                while(!st.empty() && st.top().second>heights[i]){
                    index = st.top().first;
                    maxArea = max(maxArea,(i-index)*st.top().second);
                    st.pop();
                }
                st.push({index,heights[i]});
            }
        }
        while(!st.empty()){
            maxArea = max(maxArea,(i-st.top().first)*st.top().second);
            st.pop();

        }
        return maxArea;
    }
};
