class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> arr;
        for(int i=0;i<position.size();i++){
            arr.push_back({position[i], speed[i]});
        }
        sort(arr.begin(), arr.end(), greater<pair<int,int>>());

        stack<pair<int,int>> st;

        for(int i=0;i<arr.size();i++){
            if(st.empty()){
                st.push(arr[i]);
                continue;
            }

            double time = (double)(target - arr[i].first)/arr[i].second;
            double prevTime = (double)(target - st.top().first)/st.top().second;

            if(time > prevTime){
                st.push(arr[i]);
            } 
        } 
        return st.size();
    }
};
