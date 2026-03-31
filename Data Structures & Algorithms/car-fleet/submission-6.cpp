class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> arr;
        for(int i=0;i<position.size();i++){
            pair<int,int> s{position[i],speed[i]};
            arr.push_back(s);
        }

        sort(arr.begin(),arr.end(),greater<pair<int,int>>());
        stack<double> st;
        for(int i=0;i<arr.size();i++){
            double timeToReach = (target-arr[i].first)/(double)arr[i].second;
            if(st.empty()){
                st.push(timeToReach);
                continue;
            }

            if(timeToReach>st.top()){
                st.push(timeToReach);
            }
        }
        return st.size();
    }
};
