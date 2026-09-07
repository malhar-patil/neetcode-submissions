class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<pair<int, int>> st;
        vector<pair<int, int>> arr;
        for(int i=0;i<position.size();i++){
            arr.push_back({position[i], speed[i]});
        }

        sort(arr.begin(), arr.end(), greater<>());

        for(int i=0;i<arr.size();i++){
            if(st.empty()){
                st.push(arr[i]);
                continue;
            }

            double temp = (target-arr[i].first)/(double)arr[i].second;
            double temp2 = (target-st.top().first)/(double)st.top().second;

            if(temp > temp2){
                st.push(arr[i]);
            }
        }

        return st.size();
    }
};
