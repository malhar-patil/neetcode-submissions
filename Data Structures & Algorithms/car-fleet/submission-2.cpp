class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<pair<int,int>> st;
        vector<pair<int,int>> arr;

        for(int i=0;i<position.size();i++){
            pair<int,int> temp = {position[i],speed[i]};
            arr.push_back(temp);
        }

        sort(arr.begin(),arr.end());

        for(int i=arr.size()-1;i>=0;i--){
            if(st.empty()){
                st.push(arr[i]);
                continue;
            }

            pair<int,int> temp = st.top();

            double curr = (target-arr[i].first)/(double)arr[i].second;
            double prev = (target-temp.first)/(double)temp.second;

            if(curr>prev){
                st.push(arr[i]);
            }
        }

        int ans=0;
        while(!st.empty()){
            ans++;
            st.pop();
        }
        return ans;
    }
};
