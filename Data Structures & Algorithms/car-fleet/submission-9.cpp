class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> arr;
        for(int i=0;i<position.size();i++){
            arr.push_back({position[i],speed[i]});
        }
        sort(arr.begin(),arr.end());
        stack<double> st;
        for(int i=arr.size()-1;i>=0;i--){
            double val = (target - arr[i].first)/(double)arr[i].second;
            if(st.empty()){
                st.push(val);
                continue;
            }
            if(val > st.top()){
                st.push(val);
            }
        }
        return st.size();
    }
};
