class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> st;
        int res = 0;
        for(int i=0;i<heights.size();i++){
            if(st.empty() || heights[i]>= st.top().second){
                st.push({i,heights[i]});
                continue;
            }
            int index = 0;
            while(!st.empty() && st.top().second > heights[i]){
                index = st.top().first;
                res = max(res, (i - index) * st.top().second);
                st.pop();
            }
            st.push({index,heights[i]});
        }
        while(!st.empty()){
            int temp = (heights.size()-st.top().first) * st.top().second;
            cout<<temp<<endl;
            res = max(res,temp);
            st.pop();
        }
        return res;
    }
};
